#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(void) {
  pid_t pid =  -1;
  pid_t ppid = -1;
  pid_t pgpid = -1;

  // 当前进程号
  pid = getpid();

  // 当前父进程号
  ppid = getppid();

  // 当前进程组号 get process group id
  pgpid = getpgid(pid);
  
  printf("pid = %d\n", pid);
  printf("ppid = %d\n", ppid);
  printf("pgpid = %d\n", pgpid);
  return 0;
}
