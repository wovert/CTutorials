#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>


#define SOCKET_IP "172.23.26.224"
#define SOCKET_PORT 8080
#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
  // 1.创建套接字
  int sock_fd;
  sock_fd = socket(AF_INET, SOCK_STREAM, 0);

  // 2.绑定
  struct sockaddr_in addr;
  addr.sin_family = AF_INET; // ipv4
  addr.sin_port = htons(SOCKET_PORT); // port
  
  //addr.sin_addr.s_addr = INADDR_ANY; // 绑定通配符地址:本机所有IP绑定
  inet_pton(AF_INET, SOCKET_IP, &addr.sin_addr.s_addr);
  int ret = bind(sock_fd, (struct sockaddr *)&addr, sizeof(addr));
  if (ret < 0) {
    perror("bind");
    exit(0);
  }


  // 3.监听套接字 128: 已完成连接队列和未完成连接队列之和最大值
  listen(sock_fd, 128);


  // 4. 已完成连接队列里提取
  struct sockaddr_in cliaddr;
  int client_fd;
  
  socklen_t len = sizeof(cliaddr);
  client_fd = accept(sock_fd, (struct sockaddr *)&cliaddr, &len);


  char ip[16] = "";
  short port;
  printf("新的连接\n");
  inet_ntop(AF_INET, &cliaddr.sin_addr.s_addr, ip, 16);
  port = ntohs(cliaddr.sin_port);

  printf("new Client ip=%s port=%d\n", ip, port);

  // 5.读写数据
  char buf[BUF_SIZE] = "";
  while(1) {
    bzero(buf, sizeof(buf));

    // 从键盘获取数据
    int n = read(STDIN_FILENO, buf, sizeof(buf));

    //  写给客户端用户数据
    write(client_fd, buf, n);

    // 读取客户端发送的数据
    n = read(client_fd, buf, sizeof(buf));

    if (0 == n) {
      printf("客户端关闭\n");
      break; 
    }
    printf("从客户端读取到：%s\n", buf);
  }

  // 关闭
  close(client_fd);
  close(sock_fd);
}
