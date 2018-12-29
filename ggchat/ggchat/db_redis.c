/**
 * Libre IM Server
 * autor:   Libre
 * email:   libre@aliyun.com
 * data:    16/4/16
 */
#include <stdlib.h>
#include <string.h>
#include "opt.h"
#include "db_redis.h"
#include "package.h"
#include "utils.h"

static eredis_t *e;
static eredis_t *e_local;
void init_redis_pool(){
    e = eredis_new();
    e_local = eredis_new();

    /* Set timeout - default 5000ms */
    eredis_timeout( e, 200 );
    eredis_timeout( e_local, 200);

    /* Set max readers - default 10 */
    eredis_r_max( e, 10 );
    eredis_r_max( e_local, 10 );

    /* Set retry for reader - default 1 */
    eredis_r_retry( e, 1 );
    eredis_r_retry( e_local, 1 );

    /* Set redis server host */
    eredis_host_add( e, libreim_settings_redis_ip, libreim_settings_redis_port );
    eredis_host_add( e_local, "127.0.0.1", libreim_settings_redis_port );
}
int save_server_fd(char *uid,int os,int fd){
    /**
     * UID:32Bit:OS ip:fd
     * SERVER:ip:fd(32Bit):OS
     */
    int ret = 0;
    eredis_reader_t *reader;
    eredis_reply_t *reply;
    reader = eredis_r(e);
    reply = eredis_r_cmd(reader,"MSET UID:%s:%d %s:%d SERVER:%s:%d %s:%d",uid,os,libreim_settings_listen,fd,libreim_settings_listen,fd, uid,os);
    if(reply->type == REDIS_REPLY_STATUS && strcasecmp(reply->str,"OK") == 0){
        ret = 1;
    }
    eredis_r_release(reader);
    return ret;
}
int save_online_uid(char *uid, int os, int fd){
    eredis_reader_t *reader;
    eredis_reply_t *reply;
    int ret = 0;
    reader = eredis_r(e);
    reply = eredis_r_cmd(reader,"SETEX ONLINE:%s:%d %d %s:%d",uid, os, libreim_settings_heartbeat_timeout, libreim_settings_listen, fd);
    if(reply->type == REDIS_REPLY_STATUS && strcasecmp(reply->str,"OK") == 0){
        ret = 1;
    }
    eredis_r_release(reader);
    return ret;
}
int save_local_online_uid(char *uid, int os, int fd){
    eredis_reader_t *reader;
    eredis_reply_t *reply;
    int ret = 0;
    reader = eredis_r(e_local);
    reply = eredis_r_cmd(reader,"SETEX ONLINE:%s:%d %d %s:%d",uid, os, libreim_settings_heartbeat_timeout, libreim_settings_listen, fd);
    if(reply->type == REDIS_REPLY_STATUS && strcasecmp(reply->str,"OK") == 0){
        ret = 1;
    }
    eredis_r_release(reader);
    return ret;
}
/**
 * 查找本地在线会员所在服务器以及FD
 */
char *_find_local_online_pc_server(const char *uid){
    char *outstr = NULL;
    eredis_reader_t *reader;
    eredis_reply_t *reply;
    reader = eredis_r(e_local);
    /* 读取PC在线信息 */
    reply = eredis_r_cmd(reader,"GET ONLINE:%s:%d",uid,OS_PC);
    if(reply->type == REDIS_REPLY_STRING) {
        outstr = (char *)malloc(reply->len);
        strcpy(outstr,reply->str);
    }
    eredis_r_release(reader);
    return outstr;
}
char *find_online_pc_server(const char *uid){
    char *outstr = NULL;
    outstr = _find_local_online_pc_server(uid);
    if(outstr != NULL)
    {
        return outstr;
    }
    eredis_reader_t *reader;
    eredis_reply_t *reply;
    reader = eredis_r(e);
    /* 读取PC在线信息 */
    reply = eredis_r_cmd(reader,"GET ONLINE:%s:%d",uid,OS_PC);
    if(reply->type == REDIS_REPLY_STRING) {
        outstr = (char *)malloc(reply->len + 1);
        strcpy(outstr,reply->str);
    }
    eredis_r_release(reader);
    return outstr;
}
char *_find_local_online_mobile_server(char *uid){
    char *outstr = NULL;
    eredis_reader_t *reader;
    eredis_reply_t *reply;
    reader = eredis_r(e_local);

    /* 读取PC在线信息 */
    reply = eredis_r_cmd(reader,"GET ONLINE:%s:%d",uid,OS_MOBILE);
    if(reply->type == REDIS_REPLY_STRING) {
        outstr = (char *)malloc(reply->len + 1);
        strcpy(outstr,reply->str);
    }

    eredis_r_release(reader);
    return outstr;
}
char *find_online_mobile_server(char *uid){
    char *outstr = NULL;
    outstr = _find_local_online_mobile_server(uid);
    if(outstr != NULL){
        return outstr;
    }
    eredis_reader_t *reader;
    eredis_reply_t *reply;
    reader = eredis_r(e);

    /* 读取PC在线信息 */
    reply = eredis_r_cmd(reader,"GET ONLINE:%s:%d",uid,OS_MOBILE);
    if(reply->type == REDIS_REPLY_STRING) {
        outstr = (char *)malloc(reply->len + 1);
        strcpy(outstr,reply->str);
    }

    eredis_r_release(reader);
    return outstr;
}
void pub_msg_queue_group(cJSON *json, struct UID_CLK *users){
    eredis_reader_t *reader;
    cJSON *mq_json;
    char *mq_item;
    struct UID_CLK *pUser = users->next;
    if (pUser == NULL) {
        return;
    }
    reader = eredis_r(e_local);
    /* 创建列队消息 */
    mq_json = cJSON_CreateObject();
    cJSON_AddNumberToObject(mq_json, NODE_STR_COM, COM_GROUP_MESSAGE);
    cJSON_AddItemToObject(mq_json, NODE_STR_DATA, json);
    while (pUser->next != NULL) {
        /* 替换TOID */
        cJSON_ReplaceItemInObject(json,NODE_STR_TO, cJSON_CreateString(pUser->uid));
        /* 替换同步key */
        cJSON_ReplaceItemInObject(json, NODE_STR_KEY, cJSON_CreateNumber(get_current_msec()));
        /* 发送到消息列队 */
        mq_item = cJSON_PrintUnformatted(mq_json);
        eredis_r_cmd(reader, "LPUSH %s:%s %s", MQ_NAME_PREFIX, libreim_settings_listen, mq_item);
        pub_save_msg_queue(mq_item);
        free(mq_item);
        pUser = pUser->next;
    }
    eredis_r_release(reader);
    cJSON_Delete(mq_json);
}
void pub_msg_queue(const char *json) {
    eredis_reader_t *reader;
    reader = eredis_r(e_local);
    eredis_r_cmd(reader, "LPUSH %s:%s %s", MQ_NAME_PREFIX, libreim_settings_listen, json);
    eredis_r_release(reader);
}
void pub_group_message_server(char *json){
    eredis_reader_t *reader;
    reader = eredis_r(e_local);
    eredis_r_cmd(reader, "LPUSH %s:%s:%s %s", MQ_NAME_PREFIX, "GROUPMSG", libreim_settings_listen, json);
    eredis_r_release(reader);
}
void pub_save_msg_queue(const char *json){
    eredis_reader_t *reader;
    reader = eredis_r(e_local);
    eredis_r_cmd(reader, "LPUSH %s:%s:%s %s", MQ_NAME_PREFIX, "SAVEMSG", libreim_settings_listen, json);
    eredis_r_release(reader);
}
void pub_mq_to_center(const char *json, const char *serv_ip){
    eredis_reader_t *reader;
    reader = eredis_r(e);
    eredis_r_cmd(reader, "LPUSH %s:%s %s", MQ_NAME_PREFIX, serv_ip, json);
    eredis_r_release(reader);
}
struct UID_CLK *find_group_members(char *gid){
    struct UID_CLK *head, *p;
    p = head = (struct UID_CLK *)malloc(sizeof(struct UID_CLK));
    eredis_reader_t *reader;
    eredis_reply_t *reply;
    reader = eredis_r(e);
    //TODO 这里需要优化查询结构,需要快速查询在线群成员
    reply = eredis_r_cmd(reader,"SMEMBERS GROUP:%s", gid);
    if(reply->type == REDIS_REPLY_ARRAY && reply->elements > 1){
        int i;
        for (i = 0; i < reply->elements; ++i) {
            struct UID_CLK *node = NULL;
            node = (struct UID_CLK *)malloc(sizeof(struct UID_CLK));
            strcpy(node->uid, reply->element[i]->str);
            p->next = node;
            p = node;
        }
        p->next = NULL;
    }

    eredis_r_release(reader);
    return head;
}
char *pop_cmq(){
    char *out = NULL;
    eredis_reader_t *reader;
    eredis_reply_t *reply;
    reader = eredis_r(e);
    reply = eredis_r_cmd(reader,"RPOP %s:%s", MQ_NAME_PREFIX, libreim_settings_listen);
    if(reply->type == REDIS_REPLY_STRING && reply->str != NULL){
        out = (char *)malloc(reply->len + 1);
        strcpy(out, reply->str);
    }
    eredis_r_release(reader);
    return out;
}