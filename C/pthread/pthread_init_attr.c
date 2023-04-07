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
    usleep(100000);
  }
  printf("\n");
  return NULL;
}


// 线程属性
int main(void) {
  int ret = -1;
  void *resp = NULL;
  pthread_attr_t attr;

  pthread_t tid;
  memset(&tid, 0, sizeof(tid));
  
  // 线程属性初始化
  ret = pthread_attr_init(&attr);
  if (0 != ret) {
    printf("pthread_attr_init failed\n");
    return 1;
  }
  printf("线程属性初始化函数 OK......\n");
  
  // 设置线程分离状态
  ret = pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
  if (0 != ret) {
    printf("pthread_attr_setdetachstate failed\n");
    return 1;
  }

  // create pthread
  ret = pthread_create(&tid, &attr, fun, NULL);
  if (0 != ret) {
    printf("pthread_create failed...\n");
    return 1;
  }

  // 测试当前线程是否为分离状态
  ret = pthread_join(tid, NULL);
  if (0 != ret) {
    printf("当前线程为分离状态\n");
  } else {
    printf("当前线程为非分离状态\n");
  }



  printf("主线程------tid:%lu\n", pthread_self());




  // 销毁线程属性
  ret = pthread_attr_destroy(&attr);
  if (0 != ret) {
    printf("pthread_attr_destory failed.\n");
    return 1;  
  }

  getchar();
  return 0;
}
