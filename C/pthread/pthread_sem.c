#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

int num = 100;

// 信号量变量
sem_t sem;


// 线程调度之后执行的任务
void *fun(void *arg) {
  int i;
  // 申请资源 可用资源减 1 -----------------------------------
  sem_wait(&sem);
  for(i='A';i<='Z';i++) {
    putchar(i);
    fflush(stdout); // 刷新缓冲区
    //printf("child thread do working %c\n", i);
    usleep(100000); // 100ms
  }
  // 释放资源 可用资源加 1
  sem_post(&sem);

  return (void *)0x3;
}

void *fun2(void *arg) {
  int i;
  // 申请资源 可用资源减 1 -----------------------------------
  sem_wait(&sem);
  for(i='a';i<'z';i++) {
    putchar(i);
    fflush(stdout);
    //printf("child2 thread do working %c\n", i);
    usleep(100000);
  }
  // 释放资源 可用资源加 1
  sem_post(&sem);
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

  // 初始化一个信号量 -------------------------------
  res = sem_init(&sem, 0, 1);
  if (0 != res) {
    printf("sem_init failed\n");
    return 1;
  }
  printf("初始化一个信号量OK\n");


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

  // 线程资源回收
  res = pthread_join(tid, &resp);
  if (0 != res) {
    printf("pthread_join failed...\n");
    return 1;
  }

  printf("主线程 resp= %p\n", resp);
  printf("主线程 resp2= %p\n", resp2);
  printf("主线程退出...\n");


  free(p);

  // 销毁信号量 ---------------------------------
  sem_destroy(&sem);

  getchar();
  return 0;
}
