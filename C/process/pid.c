#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(void) {
  pid_t pid =  -1;
  pid_t ppid = -1;
  pid_t pgpid = -1;

  pid = getpid();
  ppid = getppid();
  pgpid = getpgid(pid);
  
  printf("pid = %d\n", pid);
  printf("ppid = %d\n", ppid);
  printf("pgpid = %d\n", pgpid);
  return 0;
}
