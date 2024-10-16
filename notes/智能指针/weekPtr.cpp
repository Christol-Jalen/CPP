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
    // 弱指针不会让对象保持活动，但是共享指针会
    weak_ptr<int> wePtr1;
    {
        shared_ptr<int>shPtr1 = make_shared<int>(21);
        wePtr1 = shPtr1;
    }

    return 0;
}