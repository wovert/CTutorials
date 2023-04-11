#include <stdio.h>
#include <arpa/inet.h> // 套接字结构体
#include <sys/socket.h> // 套接字相关函数
#include <unistd.h>


#define SOCKET_IP "172.23.16.1"
#define SOCKET_PORT 8080
#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
  // 1.创建套接字
  int sock_fd;


  // AF_INET: IPv3, 流式套接字用于TCP通信, 0: 协议版本
  // return success FILE Descriptor or failed -1
  sock_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (-1 == sock_fd) {
    perror("socket");
    return 1;
  }

  // 2.连接服务器
  struct sockaddr_in addr; // pv4套接字结构体
  addr.sin_family = AF_INET; // ipv4
  addr.sin_port = htons(SOCKET_PORT); // port， host to network string
  
  // 点分十进制串转换成32位网络大段的数据
  inet_pton(AF_INET, SOCKET_IP, &addr.sin_addr.s_addr);
  
  // socket套接字，ipv4套接字结构体地址，ipv4套接字结构体大小
  connect(sock_fd, (struct sockaddr *)&addr, sizeof(addr));

  // 3.读写数据
  char buf[BUF_SIZE] = "";
  while(1) {
    
    printf("\n请输入发给服务器发送的数据：\n");	  
    // 读取用户键盘输入信息
    int n = read(STDIN_FILENO, buf, BUF_SIZE);
    
    // WRITE: 发送数据给服务器
    write(sock_fd, buf, n);

    // READ: 读取从服务器段发送的数据
    n = read(sock_fd, buf, BUF_SIZE);

    printf("从服务器端读取数据：\n");
    
    // 从服务器后去数据输出到屏幕
    write(STDOUT_FILENO, buf, n);
  }

  // 4.关闭
  close(sock_fd);
}
