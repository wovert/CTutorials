#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

// 进程相关
#include <unistd.h>

int main() {
  pid_t pid = -1;
  int i;

  pid = fork();

  if (-1 == pid) {
  	perror("fork");
	return 1;
  }
  
  if (pid == 0) {
    for (i=0; i<5; i++) {
      printf("Child process %d running....\n", i+1);
      sleep(1);
    }
    printf("Child process end!!!\n");
    exit(0);
  } 
 
  // 父进程没有处理子进程回收资源，子进程变成僵尸进程 
  //getchar();
  sleep(100);
  printf("Parentn wake up exit...\n");
  return 0;
}
