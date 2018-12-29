/**
 * Libre IM Server
 * autor:    Libre
 * email:   libre@aliyun.com
 * data:    16/6/23
 */
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "db_redis.h"
#include "pop_swap_message.h"

void *create_pop_swap_message_thread_handle(void *arg){
    while (1){
        char *out = pop_cmq();
        if(out == NULL) continue;

        /* 处理列队消息 并发送 */
        pub_msg_queue(out);
        free(out);
    }
    return 0;
}
void init_pop_swap_message_thread(){
    pthread_t t;

    //创建消息订阅线程
    int ret = pthread_create(&t, NULL, create_pop_swap_message_thread_handle, NULL);
    if(ret < 0){
        fprintf(stderr,"Error:%s\n","创建Redis消息订阅线程失败");
        exit(-1);
    }
}
