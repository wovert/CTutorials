#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/time.h>
#include <ctype.h>
#include <fcntl.h>
#include <sys/epoll.h>
#include <errno.h>
#include <error.h>

#define SOCKET_IP "172.22.21.3"
#define SOCKET_PORT 8000
#define BUF_SIZE 1024
#define OPEN_MAX 1024

int main(int argc, char *argv[]) {
  int i, lfd, cfd, nready, port, opt, ret;

  struct sockaddr_in addr, cliaddr;
  socklen_t len;
  
  port = SOCKET_PORT;
  if (2 == argc) port = atoi(argv[1]);		  
 
  lfd = socket(AF_INET, SOCK_STREAM, 0);

  opt = 1;
  setsockopt(lfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
  
  addr.sin_family = AF_INET;
  addr.sin_port = htons(port);
  
  addr.sin_addr.s_addr = INADDR_ANY; // 绑定通配符地址:本机所有IP绑定
  //inet_pton(AF_INET, SOCKET_IP, &addr.sin_addr.s_addr);
  ret = bind(lfd, (struct sockaddr *)&addr, sizeof(addr));
  if (ret < 0) {
    perror("bind");
    exit(0);
  }


  listen(lfd, 128);

  int epfd = epoll_create(1);
  struct epoll_event ev, evs[1024];
  ev.data.fd = lfd;
  ev.events = EPOLLIN;
  epoll_ctl(epfd, EPOLL_CTL_ADD, lfd, &ev);
  
  while(1) {
    nready = epoll_wait(epfd, evs, 1024, -1);
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
	   
          len = sizeof(cliaddr);
          cfd = accept(lfd, (struct sockaddr *)&cliaddr, &len);
          char ip[16] = "";
          short port;
          inet_ntop(AF_INET, &cliaddr.sin_addr.s_addr, ip, 16);
          port = ntohs(cliaddr.sin_port);
          printf("新的客户端连接 ip=%s port=%d\n", ip, port);

          // 设置cfd为非阻塞
	  int flags = fcntl(cfd, F_GETFL); // 获得cfd的标志位
          flags |= O_NONBLOCK;
	  fcntl(cfd, F_SETFL, flags);

	  // cfd上树
	  ev.data.fd = cfd;
	  ev.events = EPOLLIN | EPOLLET; // 边缘触发
	  epoll_ctl(epfd, EPOLL_CTL_ADD, cfd, &ev);

	} else if (evs[i].events & EPOLLIN) {
	  
	  while(1){
	    // cfd变化，而且是读事件变化
            //char buf[BUF_SIZE] = "";
            char buf[4] = "";
            int count = 0;

	    // read 非阻塞
            count = read(evs[i].data.fd, buf, sizeof(buf));
            //printf("count=%d\n", count);


	    // 如果读一个缓冲区没有数据，如果是带阻塞，就阻塞等等
	    // 如果非阻塞，缓冲区没有数据返回值等于-1， 并且会将errno值设置为 EAGAIN
            if (count < 0) {
	      // 缓冲区读干净了，跳转循环，继续监听
	      if (errno == EAGAIN) {
	        break;
	      }

	      // 普通错误
              perror("");
	      close(evs[i].data.fd);
	  
	      // 下树
	      epoll_ctl(epfd, EPOLL_CTL_DEL, evs[i].data.fd, &evs[i]);
	      break; 
	  
	    } else if (count == 0) {
	  
	      printf("client [%d] close\n", i);
	      close(evs[i].data.fd);
	      epoll_ctl(epfd, EPOLL_CTL_DEL, evs[i].data.fd, &evs[i]);
	      break;
	    } else {
	    
              //printf("客户端信息：%s\n", buf);
              write(STDOUT_FILENO, buf, 4);
              //write(evs[i].data.fd, buf, count);
	    }
	  }
        }
      }
    }
  }

  return 0;
}
