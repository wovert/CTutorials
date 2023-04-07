#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>


// 链表节点
typedef struct _node_t {
  int data;
  struct _node_t *next;
} node_t;

node_t *head = NULL;



// 条件变量
pthread_cond_t cond;

// 互斥变量
pthread_mutex_t mutex;



// 生产者线程
void *produce(void *arg) {

  printf("-生产者线程-\n");
  while(1) {

    // 互斥锁
    pthread_mutex_lock(&mutex);
    
    // 分配节点空间
    node_t *new = malloc(sizeof(node_t));
    if (NULL == new) {
      printf("malloc falied.\n");
      break;
    }
    memset(new, 0, sizeof(node_t));
    new->data = random() % 100 + 1; // 1-100
    new->next = NULL;

    // 头插法
    new->next = head;
    head = new;

    printf("生产者生产产品------------------ %d\n", new->data); 
    
    // 解锁
    pthread_mutex_unlock(&mutex);

    // 唤醒因为条件变量而阻塞的线程 
    pthread_cond_signal(&cond);


    // 随机睡眠
    sleep(random() % 3 + 1);
  }
  pthread_exit(NULL);
}

// 消费者线程
void *consume(void *arg) {
  printf("-消费者线程-\n");
  node_t *tmp = NULL;
  while(1) {
    // 互斥锁
    pthread_mutex_lock(&mutex);

    if (NULL == head) {
      // 等待
      // 链表尾空就会阻塞
      pthread_cond_wait(&cond, &mutex);
    }

    // 第一个节点地址赋值给临时变量 tmp
    tmp = head;

    // head 指向链表的第二个节点
    head = head->next;

    printf("消费者消费产品- %d\n", tmp->data);
    free(tmp);

    // 解锁
    pthread_mutex_unlock(&mutex);
    sleep(1); // sleep(1-3);
  }  
}

// 生产者消费模型 条件变量的模型
int main(void) {
  int res = -1;
  int i = 0;

  // 1个生产者线程和1个消费者线程
  pthread_t tid_producer;
  pthread_t tid_consumer;
  
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

  pthread_create(&tid_producer, NULL, produce, NULL);
  pthread_create(&tid_consumer, NULL, consume, NULL);
  
  // 回收线程资源
  pthread_join(tid_producer, NULL);
  pthread_join(tid_consumer, NULL);

  // 销毁信号量  *****************************************
  pthread_cond_destroy(&cond);
  pthread_mutex_destroy(&mutex);

  printf("按下回车键退出...\n");
  getchar();
  return 0;
}
