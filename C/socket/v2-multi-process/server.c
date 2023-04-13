#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>
#include <sys/wait.h>


#define SOCKET_IP "172.22.29.39"
#define SOCKET_PORT 8000
#define BUF_SIZE 1024


void free_process(int sig) {

  pid_t pid;
  while(1) {
  
    // 非阻塞方式等待任意的子进程
    pid = waitpid(-1, NULL, WNOHANG);
    
    printf("捕获到信号：%d pid=%d\n", sig, pid);
    if (pid <= 0) { // 小于0 没有要等待的子进程，全部推出了 0=没有进程 没有退
      //printf("没有要等的子进程或者没有进程\n");
      break;
    } else {
      printf("子进程 pid=%d terminated.\n", pid);
    }
  }

}


// 多进程并发服务器
int main(int argc, char *argv[]) {

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


    char ip[16] = "";
    short port;
    inet_ntop(AF_INET, &cliaddr.sin_addr.s_addr, ip, 16);
    port = ntohs(cliaddr.sin_port);

    printf("新的客户端连接 ip=%s port=%d\n", ip, port);

    // 创建子进程
    pid_t pid;
    pid = fork();
    
    if (pid < 0) {
      perror("fork");
      exit(0);

    // 子进程
    } else if(pid == 0) {
      close(sock_fd);

      while(1) {

        // 5.读写数据
        char buf[BUF_SIZE] = "";
        int n;
        //bzero(buf, sizeof(buf));

        // 从键盘获取数据
        //n = read(STDIN_FILENO, buf, sizeof(buf));

        //  写给客户端用户数据
        //write(client_fd, buf, n);

        // 读取客户端发送的数据
        n = read(client_fd, buf, sizeof(buf));
        if (n < 0) {
	  perror("read");
          close(client_fd);
          exit(0);
        } else if (n == 0) {
          printf("客户端主动关闭\n");
          close(client_fd);
	  exit(0);
	} else {	
          printf("从客户端读取到：%s\n", buf);
          
	  // 写给客户端
	  write(client_fd, buf, n);
	}
      }

    // 父进程
    } else {
      close(client_fd);
      // 回收子进程资源
      // 注册信号回调 
      struct sigaction act;
      //act.sa_flags = 0;
      act.sa_flags = SA_RESTART;
      act.sa_handler = free_process;
      sigemptyset(&act.sa_mask);
      
      sigaction(SIGCHLD, &act, NULL);
      sigprocmask(SIG_UNBLOCK, &set, NULL);
      
    }
  }
  
  // 关闭
  close(sock_fd);
  return 0;
}
