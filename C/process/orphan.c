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
  
  if (pid > 0) {
    printf("parent child start\n");
    sleep(1);
    printf("parent child end!!!\n");
    exit(0);
  } 
  
  while(1) {
    printf("Child process running...");
    sleep(1);
  }

  return 0;
}
