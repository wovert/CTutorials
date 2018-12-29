/**
 * Libre IM Server
 * autor:   Libre
 * email:   libre@aliyun.com
 * data:    16/4/14
 */

#ifndef LIBREIMSERVER_OPT_H
#define LIBREIMSERVER_OPT_H

/* 重命名 */
#define IM_CONST_YES 1
#define IM_CONST_NO  0

/* 列队名称前缀 */
#define MQ_NAME_PREFIX "MQ"

/* JSON节点名称 */
#define NODE_STR_KEY "key"
#define NODE_STR_ME  "me"
#define NODE_STR_GID "gid"
#define NODE_STR_TO  "to"
#define NODE_STR_OS  "os"
#define NODE_STR_COM "command"
#define NODE_STR_DATA "data"

/* 登录设备 */
#define OS_MOBILE   1
#define OS_PC       2

/* 程序设置 */
char *libreim_settings_encrypt_key;
char *libreim_settings_listen;
char *libreim_settings_redis_ip;
char *libreim_settings_redis_local_ip;
char *libreim_settings_mongodb_ip;
char *libreim_settings_mongodb_dbname;
char *libreim_settings_mongodb_collname;
char *libreim_settings_pidfile;
char *libreim_settings_logfile;
int libreim_settings_heartbeat_timeout;
int libreim_settings_daemon;
int libreim_settings_port;
int libreim_settings_redis_port;
int libreim_settings_send_max_threads;

/* 定义一些类型 */
struct UID_CLK{
    char uid[33];
    struct UID_CLK *next;
};

/* 定义一些简单的链表函数 */

#endif //LIBREIMSERVER_OPT_H
