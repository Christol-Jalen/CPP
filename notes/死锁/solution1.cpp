/*
死锁解决方法1: 避免嵌套锁（Lock Ordering）
确保所有线程以相同的顺序获取锁，这样可以避免循环等待的条件，从而预防死锁的发生。
*/

#include <mutex>
#include <thread>
#include <iostream>

std::mutex mutex1;
std::mutex mutex2;

void threadFunction1() 
{
    std::lock(mutex1, mutex2); // 使用 std::lock 获取多个锁，避免死锁
    std::lock_guard<std::mutex> lock1(mutex1, std::adopt_lock);
    std::lock_guard<std::mutex> lock2(mutex2, std::adopt_lock);
    std::cout << "Thread 1 acquired both mutexes.\n";
}

void threadFunction2() 
{
    std::lock(mutex1, mutex2); // 同样使用 std::lock，确保锁的顺序和threadFunction1一致
    std::lock_guard<std::mutex> lock1(mutex1, std::adopt_lock);
    std::lock_guard<std::mutex> lock2(mutex2, std::adopt_lock);
    std::cout << "Thread 2 acquired both mutexes.\n";
}

int main() 
{
    std::thread t1(threadFunction1);
    std::thread t2(threadFunction2);
    t1.join();
    t2.join();
    return 0;
}
