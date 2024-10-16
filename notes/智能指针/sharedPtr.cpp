#include <iostream>
#include <memory>
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
    shared_ptr<MyClass> shPtr1 = make_shared<MyClass>();
    cout << "Shared count: " << shPtr1.use_count() << endl; // 显示shPtr1的引用计数， =1
    { // ------ shPtr2作用域开始 ------
        shared_ptr<MyClass> shPtr2 = shPtr1;
        cout << "Shared count: " << shPtr1.use_count() << endl; // =2
    } // ------ shPtr2作用域结束 ------
    cout << "Shared count: " << shPtr1.use_count() << endl; // =1（shPtr2作用结束，因此引用计数-1）

    return 0;
}
