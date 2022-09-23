#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int g_num = 100;

int main() {
  
  pid_t pid = -1;
  int *p;
  int num = 10;

  p = malloc(sizeof(int));
  if (p == NULL) {
    printf("malloc failed...\n");
    return 1;
  }
  memset(p, 0, sizeof(int));
  *p = 200;

  pid = fork();

  if (-1 == pid) {
  	perror("fork");
	return 1;
  }
  
  if (pid == 0) {
    // child process
    printf("Child process pid=%d ppid=%d\n", getpid(), getppid());
    printf("Child num=%d\n", num++);
    printf("Child num=%d\n", num);
    printf("Child g_num=%d\n", g_num++);
    printf("Child g_num=%d\n", g_num);
    printf("Child *p=%d\n", (*p)++);
    printf("Child *p=%d\n", *p);
    printf("-----------\n");
    free(p);
  } else {
    printf("Parent process pid=%d cpid=%d ppid=%d\n", getpid(), pid, getppid());
    printf("-----------\n");
    sleep(1);
    printf("Parent num=%d\n", num);
    printf("Parent g_num=%d\n", g_num);
    printf("Parent *p=%d\n", *p);
    free(p);
  }
  
  return 0;
}
