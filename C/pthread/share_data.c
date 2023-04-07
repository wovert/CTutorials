#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <pthread.h>


int num = 100;

// 线程调度之后执行的任务
void *fun(void *arg) {
  int *pn = (int *) arg;
  printf("线程1 before in fun number=%d, *pn=%d\n", num, *pn);
  num++;
  (*pn)++;
  printf("线程1 after in fun number=%d, *pn=%d\n", num, *pn);

  printf("线程1 tid: %lu\n", pthread_self());
  return NULL;
}

// 线程调度之后执行的任务
void *fun1(void *arg) {
  int var = (int)(long)arg;
  printf("线程2 tid: %lu var=%d \n", pthread_self(), var);
  printf("线程2 before in fun1 number=%d\n", num);
  num++;
  printf("线程2 after in fun1 number=%d\n", num);
  return NULL;
}

// 数据段和堆
int main(void) {
  int res = -1;

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

  (*p)++;
  printf("在主线程 number=%d, *p=%d\n", num, *p);

  // create pthread
  res = pthread_create(&tid2, NULL, fun1, (void *)0x3);
  if (0 != res) {
    printf("pthread_create failed...\n");
    return 1;
  }
  printf("在主线程 end number=%d, p=%d\n", num, *p);
  free(p);
  printf("按下任意键线程退出\n");
  getchar();
  return 0;
}
