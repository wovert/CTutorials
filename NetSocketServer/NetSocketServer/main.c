#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <fcntl.h> // for open
#include <unistd.h> // for close
#include "error.h"

#define PORT 30000
#define LISTEN_LEN 5

int main(int argc, const char * argv[]) {
    
    char *advice[] = {
        "I'm PHP.\r\n",
        "I'm C/C++.\r\n",
        "I'm Go.\r\n",
        "I'm Python.\r\n",
        "I'm NodeJS.\r\n"
    };
    
    int socketfd_s; // 服务端套接字
    struct sockaddr_in address_s;
    
    // 创建套接字描述符
    socketfd_s = socket(PF_INET, SOCK_STREAM, 0);
    if(-1 == socketfd_s) {
        error("无法打开套接字");
    }
    
    address_s.sin_family = PF_INET;
    address_s.sin_port = (in_port_t)htons(PORT);
    address_s.sin_addr.s_addr = htonl(INADDR_ANY); // 允许到达服务器任何网络接口
    
    // 重新使用端口
    int reuse = 1;
    if (setsockopt(socketfd_s, SOL_SOCKET, SO_REUSEADDR, (char *)&reuse, sizeof(int)) == -1) {
        error("无法设置套接字'重新使用端口'");
    }
    
    // 绑定端口
    if (bind(socketfd_s, (struct sockaddr *) &address_s, sizeof(address_s)) == -1) {
        error("无法绑定端口");
    }
    printf("监听端口：%d\n", PORT);
    
    // 监听
    if (listen(socketfd_s, LISTEN_LEN) == -1) {
        error("无法监听");
    }
    printf("开始监听队列：%d\n", LISTEN_LEN);

    // 接受连接
    while(1) {
        struct sockaddr_in address_c;
        unsigned int address_size = sizeof(address_c);
        
        // 接受客户端请求
        int socketfd_c = accept(socketfd_s, (struct sockaddr *) &address_c, &address_size);
        if (socketfd_c == -1) {
            error("无法监听");
        }
        
        printf("Client IP is :%s\n",inet_ntoa(address_c.sin_addr));
        
        printf("接口客户端请求：%d\n", socketfd_c);
        char *msg = advice[rand() % 5];
        
        
        // 开始客户端通信
        send(socketfd_c, msg, strlen(msg), 0);
        close(socketfd_c);
    }
    
    
    return 0;
}
