#include <iostream>
#include <vector>
using namespace std;

// 选择排序
// ref: https://www.cnblogs.com/BobHuang/p/11263183.html

void selection_sort(vector<int>& vec){
    for(int i=0; i<vec.size()-1; i++){ // vec[i]为每次遍历的起点
        int minIndex = i; // 储存未被排序部分的最小数的index, 用i初始化
        for(int j=i+1; j<vec.size(); j++){ // 遍历未被排序的部分
            if(vec[j] < vec[minIndex]){
                minIndex = j; // 更新最小index
            }
        }
        swap(vec[i], vec[minIndex]); // 将最小的数字放在当前遍历的起点
    }
}


// 主函数
int main() {
    vector<int> vec = {64, 34, 25, 12, 22, 11, 90};
    selection_sort(vec);
    cout << "Sorted array: ";
    for(int i=0; i<vec.size(); i++){
        cout << vec[i] << " ";
    }
    cout << endl;
    return 0;
}