#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

// 互斥量
pthread_mutex_t mutex;

// 条件变量
pthread_cond_t cond;



int num = 0;
int flag = 0;

// 改变条件的线程
void *fun1(void *arg) {

  printf("线程1开始执行\n");
  while(1) {
    // 加锁
    pthread_mutex_lock(&mutex);

    flag = 1;

    // 解锁
    pthread_mutex_unlock(&mutex);
    
    
    // 唤醒因为条件变量而阻塞线程
    pthread_cond_signal(&cond);

    sleep(2);
  }
}

// 等待条件 如果成立就往下执行
void *fun2(void *arg) {
  printf("线程2开始执行\n");
  while(1) {
    // 加锁
    pthread_mutex_lock(&mutex);

    // 条件不满足
    if (0 == flag) {
      // 等待条件满足，会阻塞 释放锁
      pthread_cond_wait(&cond, &mutex);
    }
    printf("线程2因为条件满足开始运行...\n");
    flag = 0;
    // 解锁
    pthread_mutex_unlock(&mutex);
  }  
}

// 读写锁
int main(void) {
  int res = -1;
  int i = 0;

  pthread_t tid1;
  pthread_t tid2;
  
  // 设置随机种子
  srandom(getpid());

  // 初始化条件变量 ************************************
  res = pthread_cond_init(&cond, NULL);
  if (0 != res) {
    printf("pthread_cond_init failed\n");
    return 1;
  }

  // 初始化互斥量
  res = pthread_mutex_init(&mutex, NULL);
  if (0 != res) {
    printf("pthread_mutex_init failed\n");
    return 1;
  }

  pthread_create(&tid1, NULL, fun1, NULL);
  pthread_create(&tid2, NULL, fun2, NULL);
  

  printf("主线程------tid:%lu\n", pthread_self());


  res = pthread_join(tid1, NULL);
  if (0 != res) {
    printf("pthread_join faled\n");
    return 1;
  }

  res = pthread_join(tid2, NULL);
  if (0 != res) {
    printf("pthread_join faled\n");
    return 1;
  }

  // 销毁互斥量和条件变量 *****************************************
  pthread_mutex_destroy(&mutex);
  pthread_cond_destroy(&cond);

  printf("按下回车键退出...\n");
  getchar();
  return 0;
}
