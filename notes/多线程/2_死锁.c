#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


// 定义两个互斥锁
pthread_mutex_t lock1;
pthread_mutex_t lock2;

void* thread1_func(void* arg){
    printf("线程1: 尝试获取lock1...\n");
    pthread_mutex_lock(&lock1); /////////////////////
    printf("线程1: 已获取lock1\n");

    sleep(1); // 使线程2有时间获取lock2

    printf("线程2: 尝试获取lock2...\n");
    pthread_mutex_lock(&lock2); /////////////////////
    printf("线程2: 已获取lock2\n");

    // 释放锁
    pthread_mutex_unlock(&lock1);
    pthread_mutex_unlock(&lock2);

    pthread_exit(NULL);
}

void* thread2_func(void* arg){
    printf("线程2: 尝试获取lock2...\n");
    pthread_mutex_lock(&lock2); /////////////////////
    printf("线程2: 已获取lock2\n");

    sleep(1);

    printf("线程2: 尝试获取lock1...\n");
    pthread_mutex_lock(&lock1); /////////////////////
    printf("线程2: 已获取lock1\n");

    pthread_mutex_unlock(&lock1);
    pthread_mutex_unlock(&lock2);
    pthread_exit(NULL);

}


int main(){
    pthread_t thread1, thread2; // 线程号

    // 初始化互斥锁
    pthread_mutex_init(&lock1, NULL);
    pthread_mutex_init(&lock2, NULL);

    // 创建两个线程
    pthread_create(&thread1, NULL, thread1_func, NULL);
    pthread_create(&thread2, NULL, thread2_func, NULL);

    // 等待两个线程结束
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    // 销毁互斥锁
    pthread_mutex_destroy(&lock1);
    pthread_mutex_destroy(&lock2);
}