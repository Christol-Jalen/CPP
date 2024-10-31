#include <iostream>
#include <vector>
using namespace std;


// 参考：https://www.bilibili.com/video/BV13J411L72U/?spm_id_from=333.337.search-card.all.click&vd_source=484a3458b6bda710858441cb85eb3ad7

void bubble_sort(vector<int>& vec) {
    int length = vec.size();
    for (int i = 0; i < length - 1; i++) { // 外层循环控制排序轮数
        for (int j = 0; j < length - 1; j++) { // 内层循环进行相邻元素比较
            if (vec[j] > vec[j + 1]) { // 如果顺序错误，则交换
                swap(vec[j], vec[j + 1]);
            }
        }
    }
}

// 主函数
int main() {
    vector<int> vec = {64, 34, 25, 12, 22, 11, 90};
    bubble_sort(vec);
    cout << "Sorted array: ";
    for(int i=0; i<vec.size(); i++){
        cout << vec[i] << " ";
    }
    cout << endl;
    return 0;
}


