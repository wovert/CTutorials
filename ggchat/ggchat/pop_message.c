/**
 * Libre IM Server
 * autor:    Libre
 * email:   libre@aliyun.com
 * data:    16/6/3
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <pthread.h>
#include <unistd.h>
#include "event2/event.h"
#include "hiredis/hiredis.h"
#include "hiredis/async.h"
#include "hiredis/adapters/libevent.h"
#include "cJSON.h"
#include "opt.h"
#include "utils.h"
#include "xxtea.h"
#include "package.h"
#include "db_redis.h"
#include "pop_message.h"


pthread_t *mq_pids;

/* 增加互斥锁 */
pthread_mutex_t SEND_MUTEX;

void _send_to_client(char *mq_item, char *client_str, char *buff, size_t len){
    pthread_mutex_lock(&SEND_MUTEX);
    char serv_info[2][80];
    str_split(serv_info,client_str,":");
    if (strstr(client_str,libreim_settings_listen) != NULL) {
        write(atoi(serv_info[1]),buff,len);
    } else {
        pub_mq_to_center(mq_item, serv_info[0]);
    }
    pthread_mutex_unlock(&SEND_MUTEX);
}
void send_to_client(char *mq_item, char *to_uid, char *buff, size_t len){
    char *client_str = NULL;
    client_str = find_online_mobile_server(to_uid);
    /* 这里分两种情况如果移动端在线或者不在线 */
    if (client_str != NULL) {
        _send_to_client(mq_item, client_str, buff, len);
    }
    //PC端不在线,执行查找移动端是否在线
    client_str = find_online_pc_server(to_uid);
    if (client_str != NULL) {
        _send_to_client(mq_item, client_str, buff, len);
    }
    free(client_str);
}
void queue_message(int command, cJSON *json, char *mq_item){

    size_t encode_len = 0;
    char *encode = NULL;
    char *str = NULL;

    cJSON *node_to = cJSON_GetObjectItem(json,NODE_STR_TO);

    str = cJSON_PrintUnformatted(json);
    encode = xxtea_encrypt(str,strlen(str),libreim_settings_encrypt_key,&encode_len);

    size_t len = encode_len + PACKAGE_HEAD_LEN;
    char send_buff[len];
    package_new(encode,(int)encode_len,1,command,send_buff);

    send_to_client(mq_item, node_to->valuestring, send_buff, len);

    free(str);
    free(encode);

}

void getMessage(redisAsyncContext *c, void *r, void *priv) {
    redisReply *reply = r;
    if(reply == NULL) return;

    char *out = reply->element[1]->str;
    cJSON *msg = cJSON_Parse(out);
    if(msg == NULL) {
        goto done;
    }
    cJSON *command = cJSON_GetObjectItem(msg, NODE_STR_COM);
    cJSON *data = cJSON_GetObjectItem(msg, NODE_STR_DATA);

    /* 处理列队消息 并发送 */
    queue_message(command->valueint, data, out);

    done:;
        cJSON_Delete(msg);
        redisAsyncCommand(c, getMessage, (char*) "end-1", "BRPOP %s:%s 0",MQ_NAME_PREFIX, libreim_settings_listen);

}
void connectCallback(const redisAsyncContext *c, int status) {
    if (status != REDIS_OK) {
        fprintf(stderr, "Error: %s\n", c->errstr);
        return;
    }
}

void disconnectCallback(const redisAsyncContext *c, int status) {
    if (status != REDIS_OK) {
        fprintf(stderr, "Error: %s\n", c->errstr);
        return;
    }
}
void *create_pop_message_thread_handle(void *arg){
    signal(SIGPIPE, SIG_IGN);
    struct event_base *base = event_base_new();
    redisAsyncContext *c = redisAsyncConnect(libreim_settings_redis_local_ip,libreim_settings_redis_port);
    if (c->err) {
        /* Let *c leak for now... */
        fprintf(stderr,"%s %s\n", "系统错误", c->errstr);
        exit(-1);
    }

    redisLibeventAttach(c,base);
    redisAsyncSetConnectCallback(c,connectCallback);
    redisAsyncSetDisconnectCallback(c,disconnectCallback);
    redisAsyncCommand(c, getMessage, (char*) "end-1", "BRPOP %s:%s 0",MQ_NAME_PREFIX, libreim_settings_listen);
    event_base_dispatch(base);
    return 0;
}
void init_pop_message_thread(){
    int i;
    mq_pids = (pthread_t *)malloc(sizeof(pthread_t) * libreim_settings_send_max_threads);
    pthread_mutex_init(&SEND_MUTEX, NULL);
    //创建消息订阅线程
    for (i = 0; i < libreim_settings_send_max_threads; ++i) {
        pthread_create(&mq_pids[i], NULL, create_pop_message_thread_handle, NULL);
    }

}
