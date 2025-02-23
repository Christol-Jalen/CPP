#include <iostream>
using namespace std;

// 基类
class Shape
{
    protected: // 保护成员只能在类本身、其派生类（子类）以及友元中访问。外部代码无法直接访问。
        int width;
        int height;

    public:
        void setWidth(int w){
            width = w;
        }
        void setHeight(int h){
            height = h;
        }

};

// 派生类
class Rectangle : public Shape // 继承
{
    public:
        int getArea(){
            return (width * height);
        }

};

int main(){

    Rectangle rect;

    rect.setWidth(5);
    rect.setHeight(7);

    cout << "Total area: " << rect.getArea() << endl;

    return 0;
}