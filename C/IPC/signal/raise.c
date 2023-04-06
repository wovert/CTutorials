#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <sys/types.h>
#include <signal.h>

// 自己给自己发一个信号
int main() {
  int i = 1;

  while(1) {
    printf("do working %d\n", i);
    if (i == 4) {
      // 自己给自己发送编号15的信号
      raise(SIGTERM);
      //kill(getpid(), SIGTERM);
    }
    i++;
    sleep(1);
  }
 return 0;

}
