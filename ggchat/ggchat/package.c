/**
 * Libre IM Server
 * autor:    Libre
 * email:   libre@aliyun.com
 * data:    16/4/18
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include "package.h"

void package_head_new(int command,char *out){
    //封装包头
    PACKAGE_HEAD *pkgHead;
    pkgHead = (PACKAGE_HEAD *)malloc(sizeof(PACKAGE_HEAD));

    pkgHead->package_len = htonl(PACKAGE_HEAD_LEN);
    pkgHead->head_len = htons(PACKAGE_HEAD_LEN);
    pkgHead->version = htons(PACKAGE_VERSION);
    pkgHead->command = htonl(command);
    pkgHead->idx = htonl(1);
    memcpy(out,pkgHead,PACKAGE_HEAD_LEN);
    free(pkgHead);
}
void package_new(char *context,int len,int idx,int command, char *out){

    //封装包头
    PACKAGE_HEAD *pkgHead;
    pkgHead = (PACKAGE_HEAD *)malloc(sizeof(PACKAGE_HEAD));
    int pkg_len = len + PACKAGE_HEAD_LEN;
    pkgHead->package_len = ntohl(pkg_len);
    pkgHead->head_len = ntohs(PACKAGE_HEAD_LEN);
    pkgHead->version = ntohs(PACKAGE_VERSION);
    pkgHead->command = ntohl(command);
    pkgHead->idx = ntohl(idx);

    memcpy(out,pkgHead,PACKAGE_HEAD_LEN);
    memcpy(out + PACKAGE_HEAD_LEN,context,len);
    free(pkgHead);
}
