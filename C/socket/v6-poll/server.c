#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include <sys/select.h>
#include <sys/types.h>
#include <sys/time.h>
#include <ctype.h>
#include <poll.h>
#include <errno.h>

#define SOCKET_IP "172.22.21.3"
#define SOCKET_PORT 8000
#define BUF_SIZE 1024
#define OPEN_MAX 1024

// poll并发服务器
int main(int argc, char *argv[]) {
  int i, maxi;
  int lfd, cfd, sockfd;

  struct sockaddr_in addr, cliaddr;
  socklen_t len;
  
  int port = SOCKET_PORT;
  if (2 == argc) port = atoi(argv[1]);		  
 
  int nready; // 接受poll返回值，记录满足监听事件 fd 个数
  struct pollfd client[OPEN_MAX]; // 定义poll的数组

  // 1.创建套接字
  lfd = socket(AF_INET, SOCK_STREAM, 0);

  // 端口复用
  int opt = 1;
  setsockopt(lfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
  
  // 2.绑定
  addr.sin_family = AF_INET;
  addr.sin_port = htons(port);
  
  addr.sin_addr.s_addr = INADDR_ANY; // 绑定通配符地址:本机所有IP绑定
  //inet_pton(AF_INET, SOCKET_IP, &addr.sin_addr.s_addr);
  int ret = bind(lfd, (struct sockaddr *)&addr, sizeof(addr));
  if (ret < 0) {
    perror("bind");
    exit(0);
  }


  // 3.监听套接字
  listen(lfd, 128);

  client[0].fd = lfd; // 监听第一个文件描述符
  client[0].events = POLLIN; // lfd 监听普通读事件
    
  for(i = 1; i<OPEN_MAX; i++)
    client[i].fd = -1; // 初始化元素
  

  maxi = 0; // client数组有效元素中最大元素下标

  for(;;) {
    // 1.监听的数组首元素地址, 
    // 2.数组元素个数
    // 3.超时时间-1 永久监听 >=0 限时等待
    

    // 阻塞监听是否有客户端连接请求
    nready = poll(client, maxi+1, -1);
      
    // lfd 有读事件就绪  
    if (client[0].revents & POLLIN) {
    
      len = sizeof(cliaddr);
      
      // 4. 接受客户端连接请求
      cfd = accept(lfd, (struct sockaddr *)&cliaddr, &len);

      char ip[16] = "";
      short port;
      inet_ntop(AF_INET, &cliaddr.sin_addr.s_addr, ip, 16);
      port = ntohs(cliaddr.sin_port);

      printf("新的客户端连接 ip=%s port=%d\n", ip, port);
    
      // 找到 client 空闲的位置存放cfd
      for(i=1; i<OPEN_MAX; i++) {
        if (client[i].fd < 0) {
	  client[i].fd = cfd;
	  break;
	}
      }

      // 最大客户端连接数
      if (i == OPEN_MAX) {
        printf("too many clients\n");
	exit(-1);
      }
      

      // 设置cfd，监控读事件
      client[i].events = POLLIN;

      // 更新client最大元素下标
      if (i > maxi) maxi = i;
      
      // 没有更多就绪事件时，继续回到poll阻塞
      if (--nready <= 0) continue;

    }
    //printf("i=%d maxi=%d\n", i, maxi);

    for(i=1; i<=maxi; i++) {
      if ((sockfd = client[i].fd) < 0) continue;
      
      //printf("sockfd=%d, i=%d\n", sockfd, i);
      //printf("client[%d].revents=%d, POLLIN=%d\n", i, client[i].revents, POLLIN);

      if (client[i].revents & POLLIN) {
        
        char buf[BUF_SIZE] = "";
        int count = 0;
        count = read(sockfd, buf, sizeof(buf));
        //printf("count=%d\n", count);

        if (count < 0) {
	  // 收到RST标志: connection reset by client
          if (errno == ECONNRESET) {
	    printf("client[%d] aborted connection\n", i);
	    close(sockfd);
	    client[i].fd = -1; // poll 中不监控文件描述符，直接为-1
	  } else {
            perror("");
	    close(sockfd);
	  } 
	} else if (count == 0) {
	  printf("client [%d] close\n", i);
	  close(sockfd);
	  client[i].fd = -1;
	  
	} else {
          printf("客户端信息：%s\n", buf);
          write(i, buf, count);
	}

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
      }
    }

  }
  
  // 关闭
  close(lfd);
  return 0;
}
