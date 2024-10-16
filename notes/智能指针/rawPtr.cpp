// 此代码采用普通指针， 用于与shared pointer的比较
#include <iostream>
using namespace std;

class MyClass {
public:
    MyClass() {
        cout << "Constructor invoked" << endl;
    }
    ~MyClass() {
        cout << "Destructor invoked" << endl;
    }
};

int main() {
    // Allocate memory for MyClass object on the heap
    MyClass* rawPtr = new MyClass();

    // Use the object through rawPtr
    cout << "Using raw pointer" << endl;

    // Manually delete the object to avoid memory leak
    delete rawPtr; // 普通指针需要手动释放内存（delete调用析构函数）

    return 0;
}
