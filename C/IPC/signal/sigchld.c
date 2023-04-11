#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

void fun(int signo) {
  printf("捕捉到信号：%d\n", signo);
  printf("子进程退出\n");

  pid_t pid;
  // 非阻塞方式: 处理僵死进程，-1 等待任意一个子进程，WNOHANG 不阻塞
  while((pid = waitpid(-1, NULL, WNOHANG)) > 0)  {
    printf("child %d terminated.\n", pid);
  }
}

int main() {
  pid_t pid = -1;

  struct sigaction act;

  act.sa_handler = fun;
  act.sa_flags = 0;


  // 注册信号处理函数
  sigaction(SIGCHLD, &act, NULL);


  // create a child process
  pid = fork();
  if (-1 == pid) {
    perror("fork");
    return -1;
  }

  if (0 == pid) {
    // CP
    printf("child process sleep 2 seconds...\n");
    sleep(2);
    printf("child process exit...\n");
    exit(0);

  } else {
    // PP
    while(1) {
      printf("父进程 do working ...\n");
      sleep(1);
    }
  }
  
  return 0;

}
