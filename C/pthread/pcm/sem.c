#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

// 信号量变量
sem_t sem_producer; // 容器的个数
sem_t sem_consumer; // 可以卖产品的个数


// 链表节点
typedef struct _node_t {
  int data;
  struct _node_t *next;
} node_t;

node_t *head = NULL;

// 生产者线程
void *produce(void *arg) {

  printf("生产者线程: 循环生产产品\n");
  while(1) {

    // 申请一个资源 容器个数减1
    sem_wait(&sem_producer); 
    
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

    printf("生产者生产----------------------- %d\n", new->data); 
    
    // 通知消费者消费 可以卖的商品个数加 1
    sem_post(&sem_consumer);

    // 随机睡眠
    sleep(random() % 3 + 1);
  }
  pthread_exit(NULL);
}

// 消费者线程
void *consume(void *arg) {
  printf("消费者线程: 循环消费产品\n");
  node_t *tmp = NULL;
  while(1) {
    // 申请资源 可以卖的商品个数减 1
    sem_wait(&sem_consumer);

    if (NULL == head) {
      printf("没有任何产品可以消费，先休息...\n");
    }

    // 第一个节点地址赋值给临时变量 tmp
    tmp = head;

    // head 指向链表的第二个节点
    head = head->next;

    printf("消费者消费: %d\n", tmp->data);
    free(tmp);

    // 通知容器个数加 1
    sem_post(&sem_producer);
    sleep(random() % 3 + 1); // sleep(1-3);
  }  
}

// 生产者消费模型 条件变量的模型
int main(void) {
  int res = -1;
  int i = 0;

  // 一个生产者线程和一个消费者线程
  pthread_t tid[6];
  
  // 设置随机种子
  srandom(getpid());

  // 初始化信号量 ************************************
  res = sem_init(&sem_producer, 0, 8); // 8个容器
  if (0 != res) {
    printf("sem_init failed\n");
    return 1;
  }
  //  可以卖的商品的个数
  res = sem_init(&sem_consumer, 0, 0);
  if (0 != res) {
    printf("sem_init failed\n");
    return 1;
  }

  // 生产者线程2个 消费者线程4个
  for(i=0; i<6;i++) {
    if (i < 2) {
      pthread_create(&tid[i], NULL, produce, NULL);
    } else {
      pthread_create(&tid[i], NULL, consume, NULL);
    }
  }
  
  // 回收线程资源
  
  for(i=0; i<6;i++) {
    pthread_join(tid[i], NULL);
  }
  // 销毁信号量  *****************************************
  sem_destroy(&sem_producer);
  sem_destroy(&sem_consumer);

  printf("按下回车键退出...\n");
  getchar();
  return 0;
}
