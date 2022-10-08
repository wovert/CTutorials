#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <pthread.h>

int main(void) {
  pthread_t tid = 0;

  // 获取当前线程的线程号
  tid = pthread_self();

  printf("tid: %lu\n", tid);

  if (pthread_equal(tid, pthread_self())) {
    printf("两个线程ID相同\n");		  
  } else {
    printf("两个线程ID不相同\n");
  }

  return 0;
}
