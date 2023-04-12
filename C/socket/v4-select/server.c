#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include <sys/select.h>
#include <sys/types.h>
#include <sys/time.h>


#define SOCKET_IP "172.22.21.3"
#define SOCKET_PORT 8000
#define BUF_SIZE 1024

// select并发服务器
int main(int argc, char *argv[]) {

  int port = SOCKET_PORT;

  // 端口参数
  if (2 == argc) {
    port = atoi(argv[1]);		  
  }

  // 1.创建套接字
  int lfd;
  lfd = socket(AF_INET, SOCK_STREAM, 0);

  // 端口复用
  int opt = 1;
  setsockopt(lfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
  
  // 2.绑定
  struct sockaddr_in addr;
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


  // 3.1 最大的文件描述符
  int maxfd = lfd;
  fd_set oldset, rset;

  // 清空0
  FD_ZERO(&oldset);
  FD_ZERO(&rset);

  // 3.2 将监听套接字lfd添加到oldset集合中
  FD_SET(lfd, &oldset);

  // 遍历 FD
  while(1) {
   
    // 3.3 将oldset赋值给需要监听的集合 rset
    rset = oldset;
    
    // 1.最大文件描述符+1, 
    // 2.需要监听的[读]的文件描述符存放集合
    // 3.需要监听的[写]的文件描述符存放集合 NULL
    // 4.需要监听的[异常文件]描述符存放集合
    // 5.多长时间监听一次，NULL：永久监听 阻塞方式， 0：非阻塞
    
    // 3.4 进入内核监听[读]的文件描述符变化，返回变化的文件描述符数量
    int n = select(maxfd + 1, &rset, NULL, NULL, NULL);
    if (n < 0) {
      perror("");
      break;

    // 没有变化，继续监听
    } else if (n == 0) {
      continue;

    } else {

      // 3.5 监听lfd有变化 代表有新的连接到来
      if (FD_ISSET(lfd, &rset)) {		      
        struct sockaddr_in cliaddr;
        int cfd;
        socklen_t len = sizeof(cliaddr);
        
	// 4. 提取新的连接
        cfd = accept(lfd, (struct sockaddr *)&cliaddr, &len);

        char ip[16] = "";
        short port;
        inet_ntop(AF_INET, &cliaddr.sin_addr.s_addr, ip, 16);
        port = ntohs(cliaddr.sin_port);

        printf("新的客户端连接 ip=%s port=%d\n", ip, port);
        
	// 3.6 将client_fd 添加到oldset集合中，以下次监听
	FD_SET(cfd, &oldset);
	
	// 更新最大文件描述符
	if (cfd > maxfd) 
	  maxfd = cfd;

	// 只有lfd 继续
	if (--n == 0) 
	  continue;
      }

      // 3.7 家庭cfd有变化 遍历lfd之后的文件描述符是否再rset集合中，在则client_fd变化
      for(int i= lfd + 1; i <= maxfd; i++) {
        // 如果i文件描述符在rset集合中
	if (FD_ISSET(i, &rset)) {
	   
          char buf[BUF_SIZE] = "";
          int count = 0;
          count = read(i, buf, sizeof(buf));

          if (count < 0) {
            perror("");
	    // 出错将cfd关闭，从oldset中删除cfd
	    close(i);
	    FD_CLR(i, &oldset);
	  
	  } else if (count == 0) {
	    printf("client close\n");
	    close(i);
	    FD_CLR(i, &oldset);
	  
	  } else {
            printf("客户端信息：%s\n", buf);
            write(i, buf, count);
	  }
        }

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
  
  // 关闭
  close(lfd);
  return 0;
}
