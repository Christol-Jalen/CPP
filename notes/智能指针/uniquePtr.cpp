#include <iostream>
#include <memory>
using namespace std;

int main(){
    unique_ptr<int>unPtr1 = make_unique<int>(21);
    cout << unPtr1 << endl; // 0x151605f30
    cout << *unPtr1 << endl; // 21
    // unique_ptr<int>unPtr2 = unPtr1; // 错误示范：只能有一个独占指针指向某个资源
    unique_ptr<int>unPtr2 = std::move(unPtr1); // move：移动所有权
    // cout << *unPtr1 << endl; // nullptr
    cout << *unPtr2 << endl; // 21
    
}