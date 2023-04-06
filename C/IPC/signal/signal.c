#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <sys/types.h>
#include <sys/time.h>
#include <signal.h>


// 信号处理函数
void fun1(int signum) {
  printf("捕捉到信号: %d\n", signum);
}

void fun2(int signum) {
  printf("捕捉到信号: %d\n", signum);
}
// 信号注册函数
int main() {

  // Ctrl + c
  signal(SIGINT, fun1);

  /* Ctrl + \*/
  signal(SIGQUIT, fun2);


  int i = 1;
  while(1) {
    printf("num = %d\n", i);
    sleep(1);
    i++;
  }

  return 0;

}
