#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <pthread.h>


// 线程调度之后执行的任务
void *fun(void *arg) {
  printf("线程1 tid: %lu\n", pthread_self());
  return NULL;
}

// 线程调度之后执行的任务
void *fun1(void *arg) {
  int var = (int)(long)arg;
  printf("线程2 tid: %lu var=%d \n", pthread_self(), var);
  return NULL;
}
int main(void) {
  int res = -1;
  pthread_t tid = 0;
  pthread_t tid2 = 0;

  // create pthread
  res = pthread_create(&tid, NULL, fun, NULL);
  if (0 != res) {
    printf("pthread_create failed...\n");
    return 1;
  }

  printf("main thread------tid:%lu\n", pthread_self());

  // create pthread
  res = pthread_create(&tid2, NULL, fun1, (void *)0x3);
  if (0 != res) {
    printf("pthread_create failed...\n");
    return 1;
  }
  printf("按下任意键线程退出\n");
  getchar();
  return 0;
}
