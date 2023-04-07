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
    putchar(i);
    fflush(stdout); // 刷新缓冲区
    //printf("child thread do working %c\n", i);
    usleep(100000); // 100ms
  }
  return (void *)0x3;
}

void *fun2(void *arg) {
  printf("线程2 tid: %lu\n", pthread_self());
  int i;
  for(i='a';i<'z';i++) {
    putchar(i);
    fflush(stdout);
    //printf("child2 thread do working %c\n", i);
    usleep(100000);
  }
  return (void *)0x10;
}

// 线程分离: 线程由系统内核进行资源回收
// 不会阻塞
int main(void) {
  int res = -1;
  void *resp = NULL;
  void *resp2 = NULL;
  
  pthread_t tid;
  pthread_t tid2;
  memset(&tid, 0, sizeof(tid));
  memset(&tid2, 0, sizeof(tid2));

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

  res = pthread_create(&tid2, NULL, fun2, (void *)p);
  if (0 != res) {
    printf("pthread_create failed...\n");
    return 1;
  }
  // 设置线程分离（不会阻塞）： 由系统内核回收线程资源
  res = pthread_detach(tid2);
  if (0 != res) {
    printf("pthread_detach failed...\n");
    return 1;
  }

  // 线程资源回收
  res = pthread_detach(tid);
  if (0 != res) {
    printf("pthread_detach failed...\n");
    return 1;
  }

  int i = 0;
  for(i=0;i<30; i++) {
    printf("%d", i);
    usleep(100000);
  } 
  
  printf("主线程退出...\n");

  free(p);

  getchar();
  return 0;
}
