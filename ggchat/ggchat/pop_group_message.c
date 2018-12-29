/**
 * Libre IM Server
 * autor:    Libre
 * email:   libre@aliyun.com
 * data:    16/6/22
 */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <pthread.h>
#include "hiredis/hiredis.h"
#include "hiredis/async.h"
#include "hiredis/adapters/libevent.h"
#include "cJSON.h"
#include "opt.h"
#include "utils.h"
#include "db_redis.h"
#include "pop_group_message.h"
#include "event2/event.h"
void _push_to_queue(const char *item){

    if (item == NULL) return;

    cJSON *json, *node_gid;
    struct UID_CLK *users = NULL;

    /* 解析消息体 */
    json = cJSON_Parse(item);
    if(json == NULL){
        cJSON_Delete(json);
        return;
    }

    node_gid = cJSON_GetObjectItem(json, NODE_STR_GID);

    /* 查找群所有成员 , 这里可以优化,例如本地缓存成员信息 */
    users = find_group_members(node_gid->valuestring);

    pub_msg_queue_group(json, users);

    /* 释放内存 */
    if(users != NULL) free_uid_clk(users);
}
void getGroupMessage(redisAsyncContext *c, void *r, void *priv) {
    redisReply *reply = r;
    if(reply == NULL) return;
    _push_to_queue(reply->element[1]->str);
    redisAsyncCommand(c, getGroupMessage, (char *) "end-1", "BRPOP %s:%s:%s 0", MQ_NAME_PREFIX, "GROUPMSG",
                      libreim_settings_listen);
}
void disconnectGroupMessage(const redisAsyncContext *c, int status) {
    if (status != REDIS_OK) {
        fprintf(stderr, "GroupSubError: %s\n", c->errstr);
    }
}
void *create_pop_group_message_thread_handle(void *arg){
    signal(SIGPIPE, SIG_IGN);
    struct event_base *base = event_base_new();
    redisAsyncContext *c = redisAsyncConnect(libreim_settings_redis_local_ip,libreim_settings_redis_port);
    if (c->err) {
        /* Let *c leak for now... */
        fprintf(stderr,"%s %s\n", "系统错误", c->errstr);
        exit(-1);
    }

    redisLibeventAttach(c,base);
    redisAsyncSetDisconnectCallback(c, disconnectGroupMessage);
    redisAsyncCommand(c, getGroupMessage, (char *) "end-1", "BRPOP %s:%s:%s 0", MQ_NAME_PREFIX, "GROUPMSG",
                      libreim_settings_listen);
    event_base_dispatch(base);
    return 0;
}
void init_pop_group_message_thread(){
    //TODO 这里可以开多个线程来处理群聊信息
    pthread_t t;
    //创建消息订阅线程
    int ret = pthread_create(&t, NULL, create_pop_group_message_thread_handle, NULL);
    if(ret < 0){
        fprintf(stderr,"Error:%s\n","创建Redis消息订阅线程失败");
        exit(-1);
    }
}

