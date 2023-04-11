#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

pthread_mutex_t mutex;
pthread_mutex_t mutex2;


// 线程调度之后执行的任务
void *fun(void *arg) {
  pthread_mutex_lock(&mutex);
  printf("线程1加锁资源1 ...\n");
  pthread_mutex_lock(&mutex2);
  printf("线程1加锁资源2 ...\n");

  printf("线程1执行临界代码...\n");

  pthread_mutex_unlock(&mutex);
  pthread_mutex_unlock(&mutex2);
}

void *fun2(void *arg) {

  pthread_mutex_lock(&mutex2);
  printf("线程2加锁资源2 ...\n");
  pthread_mutex_lock(&mutex);
  printf("线程2加锁资源1 ...\n");
  
  printf("线程2执行临界代码...\n");
 
  pthread_mutex_unlock(&mutex2);
  pthread_mutex_unlock(&mutex);
}

// 回收线程的资源
int main(void) {
  int res = -1;
  
  void *resp = NULL;
  void *resp2 = NULL;

  // 初始化一个互斥量 互斥锁
  res = pthread_mutex_init(&mutex, NULL);
  if (0 != res) {
    printf("pthread_mutex_init falied.\n");
    return 1;
  }
  res = pthread_mutex_init(&mutex2, NULL);
  if (0 != res) {
    printf("pthread_mutex_init falied.\n");
    return 1;
  }

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

  /*
  int i = 0;
  for(i=0;i<10;i++) {
    printf("主线程 i=%d\n", i);
    sleep(1);
  }
  */

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

  // 销毁互斥量 互斥锁
  pthread_mutex_destroy(&mutex);
  pthread_mutex_destroy(&mutex2);
  
  printf("\n主线程退出...\n");
  getchar();
  return 0;
}
