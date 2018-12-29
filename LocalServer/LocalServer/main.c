//
//  main.c
//  LocalServer
//
//  Created by wovert on 18/12/26.
//  Copyright © 2018年 dev. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>

#define UNIX_DOMAIN "/tmp/UNIX.domain"

/*
 socket API原本是为网络通讯设计的，但后来在socket的框架上发展出一种IPC机制，就是UNIX Domain
 Socket。虽然网络socket也可用于同一台主机的进程间通讯（通过loopback地址127.0.0.1），但是UNIX Domain
 Socket用于IPC更有效率：不需要经过网络协议栈，不需要打包拆包、计算校验和、维护序号和应答等，只是将应用层数据从一个进程拷贝到另一个进程。IPC机制本质上是可靠的通讯，而网络协议是为不可靠的通讯设计的。UNIX Domain
 Socket也提供面向流和面向数据包两种API接口，类似于TCP和UDP，但是面向消息的UNIX Domain
 Socket也是可靠的，消息既不会丢失也不会顺序错乱。
 
 UNIX Domain Socket是全双工的，API接口语义丰富，相比其它IPC机制有明显的优越性，目前已成为使用最广泛的IPC机制，比如X Window服务器和GUI程序之间就是通过UNIX Domain Socket通讯的。
 使用UNIX Domain Socket的过程和网络socket十分相似，也要先调用socket()创建一个socket文件描述符，address
 family指定为AF_UNIX，type可以选择SOCK_DGRAM或SOCK_STREAM，protocol参数仍然指定为0即可。
 
 UNIX Domain Socket与网络socket编程最明显的不同在于地址格式不同，用结构体sockaddr_un表示，网络编程的socket地址是IP地址加端口号，而UNIX Domain Socket的地址是一个socket类型的文件在文件系统中的路径，这个socket文件由bind()调用创建，如果调用bind()时该文件已存在，则bind()错误返回。
 以下程序将UNIX Domain socket绑定到一个地址。
 
 
 struct sockaddr_un {
   sa_family_t sun_family;  PF_UNIX或AF_UNIX
   char sun_path[UNIX_PATH_MAX]; 路径名
 };

 */


int main(int argc, const char * argv[]) {
    // 服务端和客户端socket描述符
    int server_socketfd, client_socketfd;
    
    // 服务端和客户端套接字命名长度
    int server_len, client_len;
    
    struct sockaddr_un server_address; // 服务端地址
    struct sockaddr_un client_address; // 客户端地址
    
    unlink(UNIX_DOMAIN); // 删除套接字文件
    
    /*
     socket(int domain, int type, int protocol);
     创建套接字是通信线路的一个终点
     domain 协议组 本地套接字｜网络套接字 (AF_UNIX )
     type 套接字的通信类型 SOCKT_STREAM/TCP, SOCK_DGRAM/UDP
     protocol 使用的协议 默认0
     AF = Address Family
     PF = Protocol Family
     AF_INET = PF_INET
     windows中AF_INET与PF_INET完全一样
     BSD使用是AF,对于POSIX(可移植操作系统接口，POSIX标准定义了操作系统应该为应用程序提供的接口标准)是PF
     理论上建立socket时是指定协议，应该用PF_xxxx，设置地址时应该用AF_xxxx。
     当然AF_INET和PF_INET的值是相同的，混用也不会有太大的问题。
     socket时候用PF_xxxx或AF_xxxx也是没关系的，只是不符合规范
    */
    server_socketfd = socket(AF_UNIX, SOCK_STREAM, 0);  // 创建套接字并返回套接字描述符
    server_address.sun_family = AF_UNIX; // 类Unix文件系统实现本地套接字
    // 套接字文件名存储服务端套接字文件
    strncpy(server_address.sun_path, UNIX_DOMAIN, sizeof(server_address.sun_path)-1);
    
    server_len = sizeof(server_address); // 服务端地址指针大小
    
    // 绑定本地套接字，服务端地址
    if (bind(server_socketfd, (struct sockaddr *)&server_address, server_len) == -1) {
        perror("绑定套接字不成功！");
        unlink(UNIX_DOMAIN);
        close(client_socketfd);
        exit(1);
    }
   
    // 监听5个队列
    if (listen(server_socketfd, 5) == -1) {
        perror("监听失败！");
        unlink(UNIX_DOMAIN);
        close(client_socketfd);
        exit(1);
    }
    
    while(1) {
        char ch;
        printf("服务端开始监听：\n");
        
        // 客户端地址大小
        client_len = sizeof(client_address);
        
        // 接受客户端连接并创将客户端套接字
        client_socketfd = accept(server_socketfd, (struct sockaddr *)&client_address, &client_len);
        
        // 通过客户端端套接字读区
        read(client_socketfd, &ch, 1);
        printf("读取客户端发送的数据：%c\n", ch);
        
        ch++;
        
        // 向客户端套接字加1
        write(client_socketfd, &ch, 1);
        printf("写入数据客户端socket：%c\n", ch);
        
        // 关闭客户端套接字
        close(client_socketfd);
    }
}
