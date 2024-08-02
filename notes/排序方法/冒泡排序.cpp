#include <iostream>
#include <vector>
using namespace std;

// Created by GPT4

// 函数用于执行冒泡排序
void bubbleSort(vector<int>& vec, int n) {
    bool swapped;
    for (int i = 0; i < n-1; i++) {
        swapped = false;
        for (int j = 0; j < n-i-1; j++) {
            if (vec[j] > vec[j+1]) {
                swap(vec[j], vec[j+1]);
                swapped = true;
            }
        }

        // 如果这一趟没有发生交换，说明数组已经排序好了
        if (!swapped)
            break;
    }
}

// 函数用于打印数组
void printVector(vector<int> vec, int size) {
    for (int i = 0; i < size; i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
}

// 主函数
int main() {
    vector<int> vec = {64, 34, 25, 12, 22, 11, 90};
    int n = vec.size();
    bubbleSort(vec, n);
    cout << "Sorted array: ";
    printVector(vec, n);
    return 0;
}