/**
 * Libre IM Server
 * autor:    Libre
 * email:   libre@aliyun.com
 * data:    16/4/18
 */

#ifndef LIBREIMSERVER_PACKAGE_H
#define LIBREIMSERVER_PACKAGE_H
/* 协议版本 */
#define  PACKAGE_VERSION 1
/* 定义包头长度 */
#define PACKAGE_HEAD_LEN 16

/* 定义最大封包长度 */
#define PACKAGE_BUFF_MAX_LEN 2048

/* 定义封包命令 */
#define COM_HEARTBEAT     1
#define COM_CONNECTED     2
#define SRV_CONNECTED     3
#define COM_MESSAGE       100
#define COM_GROUP_MESSAGE 110
#define SYS_NOTICE        900

/* 定义一些命令对应的类型 */
#define MSG_TYPE_BROADCAST 0 //作废
#define MSG_TYPE_TEXT      1
#define MSG_TYPE_IMAGE     2
#define MSG_TYPE_SOUND     3
#define MSG_TYPE_VEDIO     4
#define MSG_TYPE_GOODS     5
/**
 定义包头结构体，包头总长度16Byte
 */
typedef struct {
    int package_len;    //包长度 	4Byte
    short head_len;	    //包头长度 	2Byte
    short version; 	    //协议版本	2Byte
    int command;	    //命令说明	4Byte
    int idx;		    //包序列号	4Byte
} PACKAGE_HEAD;

void package_head_new(int command,char *out);
void package_new(char *context,int len,int idx,int command, char *out);

#endif //LIBREIMSERVER_PACKAGE_H
