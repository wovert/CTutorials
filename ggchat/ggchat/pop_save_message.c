/**
 * Libre IM Server
 * autor:    Libre
 * email:   libre@aliyun.com
 * data:    16/7/13
 */

#include <stdlib.h>
#include <sys/param.h>
#include <pthread.h>
#include "hiredis/async.h"
#include "hiredis/adapters/libevent.h"
#include "event2/event.h"
#include "cJSON.h"
#include "mongoc.h"
#include "opt.h"
#include "pop_save_message.h"


void getSaveMessage(redisAsyncContext *c, void *r, void *priv) {

    //TODO 需要对列队消息处理然后保存到MongoDB,建立BSON对象然后存到数据库中
    redisReply *reply = r;
    if(reply == NULL) return;

    cJSON *msg;
    bson_error_t error;
    bson_oid_t oid;
    bson_t *doc;

    doc = bson_new ();
    msg = cJSON_Parse(reply->element[1]->str);
    bson_oid_init (&oid, NULL);
    //BSON_APPEND_OID (doc, "_id", &oid);
    BSON_APPEND_UTF8 (doc, "hello", "world");

    if (!mongoc_collection_insert ((mongoc_collection_t *)priv, MONGOC_INSERT_NONE, doc, NULL, &error)) {
        fprintf (stderr, "%s\n", error.message);
    }

    bson_destroy (doc);

    /* 继续读取消息列队 */
    redisAsyncCommand(c, getSaveMessage, priv, "BRPOP %s:%s:%s 0", MQ_NAME_PREFIX, "SAVEMSG",
                      libreim_settings_listen);
}
void disconnectSaveMessage(const redisAsyncContext *c, int status) {
    if (status != REDIS_OK) {
        fprintf(stderr, "Error: %s\n", c->errstr);
        return;
    }
}
void *create_save_message_thread_handle(void *arg){
    signal(SIGPIPE, SIG_IGN);


    char mongodb_conn_str[100];
    mongoc_client_t *mongo_client;
    mongoc_collection_t *mongo_coll;

    /* 初始化MongoDB库 */
    mongoc_init();
    /* 定义MongoDB数据库链接字符串 */
    sprintf(mongodb_conn_str, "mongodb://%s", libreim_settings_mongodb_ip);
    /* 建立MongoDB数据库客户端 */
    mongo_client = mongoc_client_new(mongodb_conn_str);
    /* 获取MongoDB数据单元 */
    mongo_coll = mongoc_client_get_collection(mongo_client, libreim_settings_mongodb_dbname, libreim_settings_mongodb_collname);


    struct event_base *base = event_base_new();
    redisAsyncContext *c = redisAsyncConnect(libreim_settings_redis_local_ip,libreim_settings_redis_port);
    if (c->err) {
        /* Let *c leak for now... */
        fprintf(stderr,"%s %s\n", "系统错误", c->errstr);
        exit(-1);
    }

    redisLibeventAttach(c,base);
    redisAsyncSetDisconnectCallback(c, disconnectSaveMessage);
    redisAsyncCommand(c, getSaveMessage, mongo_coll, "BRPOP %s:%s:%s 0", MQ_NAME_PREFIX, "SAVEMSG",
                      libreim_settings_listen);
    event_base_dispatch(base);
    return 0;
}
void init_pop_save_message_thread(){
    pthread_t t;
    //创建消息订阅线程
    int ret = pthread_create(&t, NULL, create_save_message_thread_handle, NULL);
    if(ret < 0){
        fprintf(stderr,"Error:%s\n","创建Redis消息订阅线程失败");
        exit(-1);

    }
}
