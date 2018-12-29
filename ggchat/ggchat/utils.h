/**
 * Libre IM Server
 * autor:    Libre
 * email:   libre@aliyun.com
 * data:    16/4/18
 */

#ifndef LIBREIMSERVER_UTILS_H
#define LIBREIMSERVER_UTILS_H

#include <stdio.h>
#include <stdint.h>
void phex(uint8_t* str,int len);
long get_current_msec();
void get_client_ip(int fd, char *ip_str,int *port_p);
int str_split(char dst[][80], char* str, const char* spl);
void cut_online_server_info(char *src,char *ip, int *fd);
void free_uid_clk(struct UID_CLK *sList);


#endif //LIBREIMSERVER_UTILS_H
