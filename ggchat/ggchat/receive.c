/**
 * Libre IM Server
 * autor:    Libre
 * email:   libre@aliyun.com
 * data:    16/4/19
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "xxtea.h"
#include "opt.h"
#include "db_redis.h"
#include "package.h"
#include "receive.h"
#include "cJSON.h"
#include "utils.h"

/**
 * 响应客户端发出连接命令
 */
void response_connected(struct bufferevent *bev,char *buff,size_t len){
    char package_conn_buff[PACKAGE_HEAD_LEN];
    struct evbuffer *ev_buff;
    struct evbuffer *ev_out = bufferevent_get_output(bev);
    int fd;

    /* 解密数据 */
    size_t decode_len;
    char *decode = xxtea_decrypt(buff,len,libreim_settings_encrypt_key,&decode_len);
    cJSON *json_root = cJSON_Parse(decode);
    if (json_root == NULL) {
        cJSON_Delete(json_root);
        return;
    }

    cJSON *node_me = cJSON_GetObjectItem(json_root,NODE_STR_ME);
    cJSON *node_os = cJSON_GetObjectItem(json_root,NODE_STR_OS);

    /* 记录登录信息 */
    fd = (int)bufferevent_getfd(bev);
    int ret = save_server_fd(node_me->valuestring,node_os->valueint,fd);

    if(ret == 0) goto done;

    /* 返回链接成功 */
    ev_buff = evbuffer_new();
    package_head_new(SRV_CONNECTED, package_conn_buff);
    evbuffer_add(ev_buff,package_conn_buff,PACKAGE_HEAD_LEN);
    evbuffer_add_buffer(ev_out,ev_buff);

    done:;
        cJSON_Delete(json_root);
        free(decode);
}
/**
 * 响应心跳
 */
void response_heartbeat(struct bufferevent *bev, char *buff, size_t len){
    char send_buff[PACKAGE_HEAD_LEN];
    struct evbuffer *out;
    out = bufferevent_get_output(bev);
    int fd = (int)bufferevent_getfd(bev);

    size_t decode_len = 0;
    char *decode = xxtea_decrypt(buff,len,libreim_settings_encrypt_key,&decode_len);

    cJSON *json_root = cJSON_Parse(decode);
    if(json_root == NULL){
        cJSON_Delete(json_root);
        return;
    }
    cJSON *node_me = cJSON_GetObjectItem(json_root,NODE_STR_ME);
    cJSON *node_os = cJSON_GetObjectItem(json_root,NODE_STR_OS);

    /* 纪录在线客户端信息 分别记录在主库和本地Redis */
    int ret = save_online_uid(node_me->valuestring, node_os->valueint, fd);
    if (ret == 0) return;
    ret = save_local_online_uid(node_me->valuestring, node_os->valueint, fd);
    if (ret == 0) return;

    /* 发送心跳回应给客户端 */
    package_head_new(COM_HEARTBEAT,send_buff);
    evbuffer_add(out,send_buff,PACKAGE_HEAD_LEN);

    cJSON_Delete(json_root);
    free(decode);
}
/**
 * 响应普通消息
 */
void response_message(struct bufferevent *bev, char *buff, size_t len) {

    char *pub_str;
    size_t decode_len = 0;
    char *decode;
    /* 解密数据 */
    decode = xxtea_decrypt(buff,len,libreim_settings_encrypt_key,&decode_len);
    cJSON *j_msg = cJSON_Parse(decode);
    if(j_msg == NULL){
        cJSON_Delete(j_msg);
        return;
    }

    cJSON *json = cJSON_CreateObject();
    cJSON_ReplaceItemInObject(j_msg, NODE_STR_KEY, cJSON_CreateNumber(get_current_msec()));
    cJSON_AddNumberToObject(json, NODE_STR_COM, COM_MESSAGE);
    cJSON_AddItemToObject(json, NODE_STR_DATA, j_msg);

    pub_str = cJSON_PrintUnformatted(json);

    pub_msg_queue(pub_str);
    pub_save_msg_queue(pub_str);

    cJSON_Delete(json);
    free(decode);
    free(pub_str);
}

/*
 * 响应群聊消息
 */
void response_group_message(struct bufferevent *bev, char *buff, size_t len){

    /* 解码消息 */
    size_t decode_len = 0;
    char *decode = NULL;
    decode = xxtea_decrypt(buff,len,libreim_settings_encrypt_key,&decode_len);
    pub_group_message_server(decode);
    free(decode);
}

void receive_buff(struct bufferevent *bev,char *buff){
    size_t len,head_len;
    PACKAGE_HEAD *package_head;
    package_head = (PACKAGE_HEAD *)malloc(sizeof(PACKAGE_HEAD));
    /* 解析协议包头 */
    memcpy(package_head,buff,PACKAGE_HEAD_LEN);

    /* 封包体内容长度 */
    head_len = ntohs(package_head->head_len);
    len = ntohl(package_head->package_len) - head_len;
    char *body_buff = buff + head_len;

    switch (ntohl(package_head->command)){
        case COM_MESSAGE:
            response_message(bev,body_buff,len);
            break;
        case COM_GROUP_MESSAGE:
            response_group_message(bev, body_buff, len);
            break;
        case COM_CONNECTED:
            response_connected(bev,body_buff,len);
            break;
        case COM_HEARTBEAT:
            response_heartbeat(bev, body_buff, len);
            break;
    }
    free(package_head);
}
