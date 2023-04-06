#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <sys/types.h>
#include <sys/time.h>
#include <signal.h>


// 信号处理函数
void fun(int signum) {
  printf("旧的信号处理函数捕捉到信号: %d\n", signum);
}

// 新的信号处理函数
void fun1(int signum, siginfo_t *info, void *context) {
  printf("新的信号处理函数捕捉到信号: %d\n", signum);

}
// 信号注册函数
int main() {

  int ret = -1;

#if 0
  struct sigaction act;

  // 使用旧的信号处理函数指针
  act.sa_handler = fun;

  // 标志为默认 默认使用旧的信号处理函数指针
  act.sa_flags = 0;
#else
  
  struct sigaction act;
  // 使用新的信号处理函数指针
  act.sa_sigaction = fun1;

  // 标志指定使用新的信号处理函数指针
  act.sa_flags = SA_SIGINFO;
#endif
  // 信号注册
  ret = sigaction(SIGINT, &act, NULL);
  if (-1 == ret) {
    perror("sigaction");
    return 1;
  }

  printf("按下回车键退出\n");
  getchar();
  getchar();
  
  return 0;

}
