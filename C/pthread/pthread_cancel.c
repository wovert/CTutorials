#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

int num = 100;

// 线程调度之后执行的任务
void *fun(void *arg) {
  printf("线程1 tid: %lu\n", pthread_self());
  int i;
  for(i='A';i<='Z';i++) {
    if ('W' == i) {
      pthread_exit((void *)0xc);
    }
    putchar(i);
    fflush(stdout); // 刷新缓冲区
    sleep(1);
  }
  return (void *)0x3;
}


// 线程退出
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


  sleep(3);
  printf("主线产生睡眠3秒 取消子线程..\n");
  pthread_cancel(tid);


  // 线程资源回收
  res = pthread_join(tid, &resp);
  if (0 != res) {
    printf("pthread_join failed...\n");
    return 1;
  }
  printf("线程1结束\n");

  printf("主线程 resp= %p\n", resp);
  printf("主线程退出...\n");


  free(p);

  getchar();
  return 0;
}
