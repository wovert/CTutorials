/**
 * Libre IM Server
 * autor:    Libre
 * email:   libre@aliyun.com
 * data:    16/4/18
 */
#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <sys/time.h>
#include "opt.h"
#include "utils.h"

void phex(uint8_t* str,int len)
{
    unsigned char i;
    for(i = 0; i < len; ++i)
        printf("%.2x ", str[i]);
    printf("\n");
}
long get_current_msec()
{
    struct timeval tv;
    gettimeofday(&tv,NULL);
    return tv.tv_sec * 1000 + tv.tv_usec / 1000;
}
void get_client_ip(int fd, char *ip_str,int *port_p){
    struct sockaddr_in sa;
    socklen_t len = sizeof(sa);
    getpeername(fd,(struct sockaddr *)&sa,&len);
    sprintf(ip_str,"%s",inet_ntoa(sa.sin_addr));
    *port_p = ntohs(sa.sin_port);
}
int str_split(char dst[][80], char* str, const char* spl)
{
    int n = 0;
    char *result = NULL;
    result = strtok(str, spl);
    while( result != NULL )
    {
        strcpy(dst[n++], result);
        result = strtok(NULL, spl);
    }
    free(result);
    return n;
}
void cut_online_server_info(char *src,char *ip, int *fd){
    char dst_str[2][80];
    int cut = str_split(dst_str,src,":");
    if(cut > 0) {
        size_t len = strlen(dst_str[0]);
        memcpy(ip, dst_str[0], len);
        ip[len] = '\0';
        *fd = atoi(dst_str[1]);
    }
}
void free_uid_clk(struct UID_CLK *sList )
{
    struct UID_CLK *pCur = NULL;
    struct UID_CLK *pTem = NULL;
    pCur = sList->next;
    while(pCur)
    {
        pTem = pCur->next;
        free(pCur);
        pCur = pTem;
    }
    free(sList);
    sList = NULL;
}