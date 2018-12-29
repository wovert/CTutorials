#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <string.h>
#include <sys/types.h>

#define UNIX_DOMAIN "/tmp/UNIX.domain"

int main(int argc, const char * argv[]) {
    int socketfd;
    int len;
    struct sockaddr_un address;
    int result;
    char ch = 'A';
    
    socketfd = socket(AF_UNIX, SOCK_STREAM, 0);
    address.sun_family = AF_UNIX;
    strncpy(address.sun_path, UNIX_DOMAIN, sizeof(address.sun_path)-1);
    len = sizeof(address);
    
    // 连接套接字
    result = connect(socketfd, (struct sockaddr *)&address, len);
    
    // 连接不成功
    if (result == -1) {
        perror("连接服务器套接字不成功！");
        exit(1);
    }
    
    // 向套接字写入A
    write(socketfd, &ch, 1);
    
    // 读取从服务器写入套接字内容
    read(socketfd, &ch, 1);
    
    printf("从服务器获取: %c\n", ch);
    
    // 关闭套接字
    close(socketfd);
    
    exit(0);
}
