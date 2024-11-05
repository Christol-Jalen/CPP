#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void* thread_function(void* arg){
    printf("线程运行中，参数是: %d\n", *(int *)arg);
    pthread_exit(NULL);  // 结束线程
}


int main(){
    pthread_t thread_id; // 线程id
    int arg = 5; // 传递给线程的参数
    int ret;

    // 创建线程
    ret = pthread_create(&thread_id, NULL, thread_function, (void*)&arg); // 参数：线程号，线程属性，线程执行函数，线程执行函数参数
    if(ret != 0){
        printf("线程创建失败\n");
        exit(1);
    }

    // 等待线程结束
    pthread_join(thread_id, NULL);
    printf("线程执行完毕\n");
    return 0;
}