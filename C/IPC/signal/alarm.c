#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <sys/types.h>
#include <signal.h>

// 闹钟
int main() {
  unsigned int ret = 0;

  // 第一次设置闹钟 5秒钟之后超时 发送对应的信号
  ret = alarm(5);
  printf("上一次闹钟剩下的时间是 %u\n", ret);


  sleep(2);
  // 之间没有超时的闹钟被新的设置给覆盖
  ret = alarm(4);
  printf("上一次闹钟剩下的时间是 %u\n", ret);

  printf("按下任意键继续\n");
  getchar();

  return 0;

}
