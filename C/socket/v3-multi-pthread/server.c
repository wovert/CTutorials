#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>
#include <pthread.h>
#include <sys/wait.h>


#define SOCKET_IP "172.22.29.39"
#define SOCKET_PORT 8000
#define BUF_SIZE 1024

typedef struct c_info {
  int cfd;
  struct sockaddr_in cliaddr;
} CINFO;


// 子线程
void *client_fun(void *arg) {
  CINFO *info = (CINFO *)arg;
  
  char ip[16] = "";
  short port;
  inet_ntop(AF_INET, &(info->cliaddr.sin_addr.s_addr), ip, 16);
  port = ntohs(info->cliaddr.sin_port);
  printf("新的客户端连接 ip=%s port=%d\n", ip, port);


  while(1) {
    char buf[BUF_SIZE] = "";
    int count = 0;
    count = read(info->cfd, buf, sizeof(buf));
    if (count < 0) {
      perror("");
      break;
    } else if (count == 0) {
      printf("client close\n");
      break;
    } else {
      printf("客户端信息：%s\n", buf);
      write(info->cfd, buf, count);
    }
  }
  close(info->cfd);
  free(info);
}

// 多线程并发服务器
int main(int argc, char *argv[]) {

  int port = SOCKET_PORT;

  if (2 == argc) {
    port = atoi(argv[1]);		  
  }

  // 回收线程资源
  pthread_attr_t attr;
  pthread_attr_init(&attr);
  pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);

  // 信号集	
  sigset_t set;
  sigemptyset(&set);

  sigaddset(&set, SIGCHLD);
  
  // 设置屏蔽编号为SIGCHLD的信号
  sigprocmask(SIG_BLOCK, &set, NULL);

  // 1.创建套接字
  int sock_fd;
  sock_fd = socket(AF_INET, SOCK_STREAM, 0);

  // 2.绑定
  struct sockaddr_in addr;
  addr.sin_family = AF_INET; // ipv4
  addr.sin_port = htons(port); // port
  
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
  CINFO *info;

  while(1) {
 
    // 提取连接
    client_fd = accept(sock_fd, (struct sockaddr *)&cliaddr, &len);

    /*
    again:
    if ((client_fd = accept(sock_fd, (struct sockaddr *)&cliaddr, &len)) < 0) {
      if ((errno == ECONNABORTED) || (errno == EINTR))//如果是被信号中断和软件层次中断,不能退出
        goto again;
      else {
        perror("accept error");
	exit(-1);
      }  
    }
    */



    // 创建子线程
    pthread_t pthid;
    info = malloc(sizeof(CINFO));
    info->cfd = client_fd;
    info->cliaddr = cliaddr;
    pthread_create(&pthid, &attr, client_fun, info);

  }
  
  // 关闭
  close(sock_fd);
  return 0;
}
