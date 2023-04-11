#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <sys/types.h>
#include <sys/time.h>
#include <signal.h>


// 信号集处理函数
void fun1(int signum) {
  printf("捕捉到信号: %d\n", signum);
}

void fun2(int signum) {
  printf("捕捉到信号: %d\n", signum);
}


void showSet(sigset_t *set) {
  int i = 0;
  for(i = 1; i<32; i++) {
    if (sigismember(set, i)) {
      printf("信号编号%d 存在\n", i);
    } else {
      printf("信号编号%d 不存在\n", i);
    }
  }
}

// 信号注册函数
int main() {

  // 信号集集合
  sigset_t set;

  // 清空集合
  sigemptyset(&set);

  // 查看信号集合
  showSet(&set);

  putchar('\n');
  
  // 将所有的信号加入到set集合中
  sigfillset(&set);

  // 查看集合  未决集合
  showSet(&set);

  // 将信号2和3从集合中移除
  sigdelset(&set, SIGINT);
  sigdelset(&set, SIGQUIT);

  showSet(&set);
  
  // 信号2添加到集合中
  sigaddset(&set, SIGINT);
  
  showSet(&set);
  
  return 0;

}
