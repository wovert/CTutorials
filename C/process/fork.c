#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int g_num = 100;

int main() {
 

  // valgrind ./a.out 查看内存泄漏分析	
  // 1024 byte 系统调用内部分配
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

  
  // 创建一个子进程
  // 在子进程中返回 0，父进程中返子进程的 PID
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
    printf("Child *p=%d\n", *p);
    printf("Child (*p)++=%d\n", (*p)++);
    printf("Child *p=%d[%p]\n", *p, (int *)p);
    printf("-----------\n");
    free(p);
  } else {
    (*p)++;
    (*p)++;
    (*p)++;
    printf("Parent process pid=%d cpid=%d ppid=%d\n", getpid(), pid, getppid());
    printf("Parent g_num=%d\n", g_num++);
    printf("Parent *p=%d[%p]\n", *p, (int *)p);
    printf("-----------\n");
    sleep(1);
    printf("Parent num=%d\n", num);
    printf("Parent g_num=%d\n", g_num);
    printf("Parent *p=%d\n", *p);
    free(p);
  }
  
  return 0;
}
