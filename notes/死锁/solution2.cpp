/*
死锁解决方法2: 使用超时尝试
通过尝试加锁的超时机制，如果一定时间内无法获取所有需要的锁，则放弃已经获取的锁，并重新尝试。
*/

#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

std::timed_mutex mutex1, mutex2;

void ThreadA() 
{
    if (mutex1.try_lock_for(std::chrono::milliseconds(100))) {
        std::this_thread::sleep_for(std::chrono::milliseconds(1)); // Give ThreadB a chance to lock mutex2
        if (mutex2.try_lock_for(std::chrono::milliseconds(100))) {
            std::cout << "Thread A\n";
            mutex2.unlock();
        }
        mutex1.unlock();
    }
}

void ThreadB() 
{
    if (mutex2.try_lock_for(std::chrono::milliseconds(100))) {
        std::this_thread::sleep_for(std::chrono::milliseconds(1)); // Give ThreadA a chance to lock mutex1
        if (mutex1.try_lock_for(std::chrono::milliseconds(100))) {
            std::cout << "Thread B\n";
            mutex1.unlock();
        }
        mutex2.unlock();
    }
}

int main() 
{
    std::thread t1(ThreadA);
    std::thread t2(ThreadB);
    t1.join();
    t2.join();
    return 0;
}