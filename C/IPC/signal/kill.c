#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <signal.h>

int main() {
 pid_t pid = -1;
 pid = fork();
 if (-1 == pid) {
   perror("fork");
   return 1;
 }

 // CP
 if (pid == 0) {
   while(1) {
     printf("child process do work...\n");
     sleep(1);
   }
   exit(0);
 } else {
  // PP
  sleep(3);
  printf("子进程不听话，该退出...\n");
  kill(pid, 15);
  printf("父进程该结束了 已经完成了使命\n");
 }
 return 0;
}
