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
  int ret = -1;

  // 信号集
  sigset_t set;
  sigset_t oldset;

  // 信号注册
  // Ctrl + c
  signal(SIGINT, fun1);

  /* Ctrl + \*/
  signal(SIGQUIT, fun2);

  printf("按下任意键 阻塞信号2\n");
  getchar();

  sigemptyset(&oldset);
  sigemptyset(&set);
  sigaddset(&set, SIGINT);

  // 设置屏蔽编号为2的信号
  ret = sigprocmask(SIG_BLOCK, &set, &oldset);

  if (-1 == ret) {
    perror("sigprocmask");
    return 1;
  }

  printf("设置屏蔽编号为2的信号成功...\n");

  printf("按下任意键解除编号为2的信号的阻塞\n");
  getchar();

  // 将信号屏蔽集设置为原来的集合
  ret = sigprocmask(SIG_SETMASK, &oldset, NULL);
  if (-1 == ret) {
    perror("sigprocmask");
    return 1; 
  }
  
  printf("按下任意键退出\n");
  getchar();
  
  
  
  return 0;

}
