#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>


// 公共资源
void printer(char *str) {
  while(*str != 0) {
    putchar(*str);
    fflush(stdout);
    str++;
    sleep(1);
  }
  printf("\n");
}


// 线程调度之后执行的任务
void *fun(void *arg) {
  char *str = "hello ";
  printer(str);
}

void *fun2(void *arg) {
  char *str = "world";
  printer(str);
}

// 回收线程的资源
int main(void) {
  int res = -1;
  void *resp = NULL;
  void *resp2 = NULL;
  
  pthread_t tid;
  pthread_t tid2;
  memset(&tid, 0, sizeof(tid));
  memset(&tid2, 0, sizeof(tid2));

  res = pthread_create(&tid, NULL, fun, NULL);
  if (0 != res) {
    printf("pthread_create failed...\n");
    return 1;
  }

  printf("主线程------tid:%lu\n", pthread_self());

  res = pthread_create(&tid2, NULL, fun2, NULL);
  if (0 != res) {
    printf("pthread_create failed...\n");
    return 1;
  }
  // 等待线程结束 阻塞： 线程资源回收
  res = pthread_join(tid2, &resp2);
  if (0 != res) {
    printf("pthread_join failed...\n");
    return 1;
  }

  // 线程资源回收
  res = pthread_join(tid, &resp);
  if (0 != res) {
    printf("pthread_join failed...\n");
    return 1;
  }
  
  printf("主线程退出...\n");
  getchar();
  return 0;
}
