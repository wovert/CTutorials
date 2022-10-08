#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <pthread.h>

int num = 100;

// 线程调度之后执行的任务
void *fun(void *arg) {
  printf("线程1 tid: %lu\n", pthread_self());
  int i;
  for(i=0;i<5;i++) {
    printf("child thread do working %d\n", i);
    sleep(1);
  }
  return (void *)0x3;
}

// 回收线程的资源
int main(void) {
  int res = -1;
  void *resp = NULL;
  pthread_t tid;
  memset(&tid, 0, sizeof(tid));

  int *p = NULL;
  p = malloc(sizeof(int));
  if (NULL == p) {
    printf("malloc failed...\n");
    return 1;
  }


  // create pthread
  res = pthread_create(&tid, NULL, fun, (void *)p);
  if (0 != res) {
    printf("pthread_create failed...\n");
    return 1;
  }

  printf("主线程------tid:%lu\n", pthread_self());

  // 等待线程结束 阻塞
  res = pthread_join(tid, &resp);
  if (0 != res) {
    printf("pthread_join failed...\n");
    return 1;
  }

  printf("resp= %p\n", resp);
  printf("主线程退出...\n");

  getchar();
  return 0;
}
