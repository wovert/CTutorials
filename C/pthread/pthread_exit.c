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
    if ('C' == i) {
      pthread_exit((void *)0xc);
    }
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

// 线程退出
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
  // 等待线程结束 阻塞： 线程资源回收
  res = pthread_join(tid2, &resp2);
  if (0 != res) {
    printf("pthread_join failed...\n");
    return 1;
  }
  printf("线程2结束\n");

  // 线程资源回收
  res = pthread_join(tid, &resp);
  if (0 != res) {
    printf("pthread_join failed...\n");
    return 1;
  }
  printf("线程1结束\n");

  printf("主线程 resp= %p\n", resp);
  printf("主线程 resp2= %p\n", resp2);
  printf("主线程退出...\n");


  free(p);

  getchar();
  return 0;
}
