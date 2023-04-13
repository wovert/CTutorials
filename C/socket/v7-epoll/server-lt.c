#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/time.h>
#include <ctype.h>
#include <sys/epoll.h>
#include <errno.h>

#define SOCKET_IP "172.22.21.3"
#define SOCKET_PORT 8000
#define BUF_SIZE 1024
#define OPEN_MAX 1024

// poll并发服务器
int main(int argc, char *argv[]) {
  /*
  int fd[2];
  pipe(fd);

  pid_t pid;
  pid = fork();

  if (pid < 0) {
    perror("");

  // 父进程 
  } else if(pid == 0) {
    close(fd[0]);
    char buf[5];
    char ch = 'a';
    while(1) {
      sleep(3);
      memset(buf, ch++, sizeof(buf));
      write(fd[1], buf, 5);
    }
  // 子进程
  } else {
    close(fd[1]);
    // 创建树
    int epfd = epoll_create(1);
    struct epoll_event ev, evs[1];
    ev.data.fd = fd[0];
    ev.events = EPOLLIN;
    epoll_ctl(epfd, EPOLL_CTL_ADD, fd[0], &ev); // 上树
    // 监听
    while(1) {
      int n = epoll_wait(epfd, evs, 1, -1);
      if (n == 1) {
	char buf[128] = "";
        int ret = read(fd[0], buf, sizeof(buf));
	if (ret <= 0) {
	  close(fd[0]);
	  epoll_ctl(epfd, EPOLL_CTL_DEL, fd[0], &ev);
	  break;
	} else {
	  printf("%s\n", buf);
	}
      }
    }
  }
  */

  int i, lfd, cfd, nready;

  struct sockaddr_in addr, cliaddr;
  socklen_t len;
  
  int port = SOCKET_PORT;
  if (2 == argc) port = atoi(argv[1]);		  
 
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

  // 4.创建树
  int epfd = epoll_create(1);

  // 将lfd上树
  struct epoll_event ev, evs[1024];
  ev.data.fd = lfd;
  ev.events = EPOLLIN;
  epoll_ctl(epfd, EPOLL_CTL_ADD, lfd, &ev);
  while(1) {
    // 水平触发：只要读缓冲区有数据触发，频繁调用系统调用
    // 边沿触发LT: 数据来一次，只触发一次
    //
    // 监听写缓冲区变化
    // 水平触发：只要可以写，就会触发
    // 边沿触发：数据从有到无，就会触发
    nready = epoll_wait(epfd, evs, 1024, -1);
    printf("epoll wait---------------------------\n");
    if (nready < 0) {
      perror("");
      break;
    } else if (nready == 0) {
      continue;
    } else {
      // 有文件描述符变化
      for(i=0; i<nready; i++) {
        
	// 判断ldf变化，并且是读事件变化
	if (evs[i].data.fd == lfd && evs[i].events & EPOLLIN) {
	   
          // 4. 接受客户端连接请求
          len = sizeof(cliaddr);
          cfd = accept(lfd, (struct sockaddr *)&cliaddr, &len);
          char ip[16] = "";
          short port;
          inet_ntop(AF_INET, &cliaddr.sin_addr.s_addr, ip, 16);
          port = ntohs(cliaddr.sin_port);
          printf("新的客户端连接 ip=%s port=%d\n", ip, port);

	  // cfd上树
	  ev.data.fd = cfd;
	  ev.events = EPOLLIN;
	  epoll_ctl(epfd, EPOLL_CTL_ADD, cfd, &ev);

	} else if (evs[i].events & EPOLLIN) {
	  // cfd变化，而且是读事件变化
          //char buf[BUF_SIZE] = "";
          char buf[4] = "";
          int count = 0;
          count = read(evs[i].data.fd, buf, sizeof(buf));
          //printf("count=%d\n", count);

          if (count < 0) {
            perror("");
	    // 下数
	    epoll_ctl(epfd, EPOLL_CTL_DEL, evs[i].data.fd, &evs[i]);
	  } else if (count == 0) {
	    printf("client [%d] close\n", i);
	    close(evs[i].data.fd);
	    epoll_ctl(epfd, EPOLL_CTL_DEL, evs[i].data.fd, &evs[i]);
	  } else {
	    
            //printf("客户端信息：%s\n", buf);
            write(STDOUT_FILENO, buf, 4);
            //write(evs[i].data.fd, buf, count);
	  }
        }
      }
    }
  }

  return 0;
}
