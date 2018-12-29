/**
 * Libre IM Server
 * autor:    Libre
 * email:   libre@aliyun.com
 * data:    16/4/16
 */

#ifndef LIBREIMSERVER_DB_H
#define LIBREIMSERVER_DB_H

#include <stdio.h>
#include "eredis.h"
#include "cJSON.h"
#include "opt.h"

void init_redis_pool();
int save_server_fd(char *uid, int os, int fd);
int save_online_uid(char *uid, int os, int fd);
int save_local_online_uid(char *uid, int os, int fd);
char *find_online_pc_server(const char *uid);
char *find_online_mobile_server(char *uid);
void pub_group_message_server(char *json);
void pub_msg_queue_group(cJSON *json, struct UID_CLK *users);
void pub_msg_queue(const char *json);
void pub_save_msg_queue(const char *json);
void pub_mq_to_center(const char *json, const char *serv_ip);
struct UID_CLK *find_group_members(char *gid);
char *pop_cmq();
#endif //LIBREIMSERVER_DB_H
