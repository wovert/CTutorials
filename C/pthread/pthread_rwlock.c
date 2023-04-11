#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

// 读写锁变量
pthread_rwlock_t rwlock;

int num = 0;

void *fun_read(void *arg) {
  // 获取线程的编号
  int index = (int)(long)arg;

  while(1) {
    // 加读锁 **************************************
    pthread_rwlock_rdlock(&rwlock);
    printf("线程%d 读取num的值 %d\n", index, num);
    // 解读锁 **************************************
    pthread_rwlock_unlock(&rwlock);
    sleep(random() % 3 + 1); // 随机睡眠1-3秒
  }
}

void *fun_write(void *arg) {
  int index = (int)(long)arg;
  while(1) {
    // 加读写锁 *************************************
    pthread_rwlock_wrlock(&rwlock);
    num++;
    printf("线程%d 修改num的值===========%d\n", index, num);
    // 接读写锁 *************************************
    pthread_rwlock_unlock(&rwlock);
    sleep(random() % 3 + 1);
  }
}

// 读写锁
int main(void) {
  int res = -1;
  int i = 0;

  // 设置随机种子
  srandom(getpid());

  // 初始化读写锁 ************************************
  res = pthread_rwlock_init(&rwlock, NULL);
  if (0 != res) {
    printf("pthread_rwlock_init failed\n");
    return 1;
  }

  // 创建8个线程
  pthread_t tid[8];
  for(i=0; i<8; i++) {
    
    //memset((void *)tid[i], 0, sizeof(tid[0]));

    long unsigned int temp = i;
    // 读线程
    if (i < 5) {
     pthread_create(&tid[i], NULL, fun_read, (void *)temp);

    // 写线程
    } else { 
     pthread_create(&tid[i], NULL, fun_write, (void *)temp);
    }
  }
  

  printf("主线程------tid:%lu\n", pthread_self());

  /*
  int i = 0;
  for(i=0;i<10;i++) {
    printf("主线程 i=%d\n", i);
    sleep(1);
  }
  */


  // 回收8个线程的资源
  for(i=0; i<8; i++) { 
    pthread_join(tid[i], NULL);
  }

  // 销毁读写锁 *****************************************
  pthread_rwlock_destroy(&rwlock);

  printf("\n主线程退出...\n");
  getchar();
  return 0;
}
