#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <sys/types.h>
#include <errno.h>
#include <signal.h>

#define PORT 30000

int main(int argc, const char * argv[]) {
    int socketfd;
    struct sockaddr_in address;
    char *buffer;
    
    socketfd = socket(PF_INET, SOCK_STREAM, 0);
    address.sin_family = PF_INET;
    address.sin_port = (in_port_t)htons(PORT);
    address.sin_addr.s_addr = htonl(inet_addr("127.0.0.1"));
    
    printf("绑定端口地址.\n");

    // 连接不成功
    char *connect_error = "连接服务器套接字失败!";
    if (connect(socketfd, (struct sockaddr *)&address, sizeof(address)) == -1) {
        fprintf(stderr, "%s: %s\n", connect_error, strerror(errno));
        exit(1);
    }
    printf("服务器连接开始.\n");

    
    int result = read(socketfd, buffer, sizeof(buffer));
    if (result == -1) {
        fprintf(stderr, "%s: %s\n", "读取套接字内容失败！", strerror(errno));
        exit(1);
    }
    
//    buffer[result] = '\0';
    printf("read %d bytes.%s", result, buffer);
    
    close(socketfd);
    exit(0);
}
