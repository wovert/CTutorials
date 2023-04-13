#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/epoll.h>

int main(int argc, char *argv[]) {

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

  return 0;
}
