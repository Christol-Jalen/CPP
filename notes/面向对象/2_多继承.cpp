#include <iostream>
using namespace std;

// 基类1: Shape
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

// 基类2: PaintCost
class PaintCost
{
    public:
        int getCost(int area){
            return area * 70;
        }

};

// 派生类
class Rectangle: public Shape, public PaintCost // 多继承
{
    public:
        int getArea(){
            return (width * height);
        }
};

int main(void){
    Rectangle rect;
    
    rect.setWidth(5);
    rect.setHeight(7);

    int area = rect.getArea();

    // 输出对象面积
    cout << "Total area: " << rect.getArea() << endl;

    // 输出总花费
    cout << "Total paint cost: $" << rect.getCost(area) << endl;
}