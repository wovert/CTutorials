#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <sys/types.h>
#include <signal.h>

int main() {
  int i = 1;

  while(1) {
    printf("do working %d\n", i);

    if (4 == i) {
      abort(); // 给自己发送异常终止编号6的信号，默认的行为就是终止进程  
    }

    i++;
    sleep(1);
  }
 return 0;

}
