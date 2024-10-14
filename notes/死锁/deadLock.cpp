#include <iostream>
#include <thread>
#include <mutex>

std::mutex mutex1, mutex2;

void ThreadA() 
{
    std::lock_guard<std::mutex> lock1(mutex1); // ThreadA先获取mutex1
    std::this_thread::sleep_for(std::chrono::milliseconds(1)); // 让ThreadB有机会锁定mutex2
    std::lock_guard<std::mutex> lock2(mutex2); // ThreadA尝试获取mutex2，但是此时这个锁已经被ThreadB持有
    std::cout << "Thread A\n";
}

void ThreadB() 
{
    std::lock_guard<std::mutex> lock2(mutex2); // ThreadB先获取mutex2
    std::this_thread::sleep_for(std::chrono::milliseconds(1)); // 让ThreadA有机会锁定mutex1
    std::lock_guard<std::mutex> lock1(mutex1); // ThreadB尝试获取mutex1， 但此时这个锁已经被ThreadA持有
    std::cout << "Thread B\n";
}

int main() 
{
    std::thread t1(ThreadA);
    std::thread t2(ThreadB);
    t1.join();
    t2.join();
    return 0;
}