#include <iostream>
#include <vector>
using namespace std;

// ref: GPT4

void quickSort(vector<int>& arr, int left, int right){
    if(left >= right) return; // 递归的结束条件

    int pivot = arr[(left + right)/2]; // 选择数据中点作为pivot
    int i = left;
    int j = right;

    while(i <= j){

        while (arr[i] < pivot) i++; // 如果左指针指向的树小于pivot，则左指针右移
        while (arr[j] > pivot) j--; // 如果右指针指向的树大于pivot，则右指针左移

        if(i<=j){ 
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    //递归
    quickSort(arr, left, j);
    quickSort(arr, i, right);
}

// 主函数
int main() {
    vector<int> vec = {64, 34, 25, 12, 22, 11, 90};
    quickSort(vec, 0, vec.size()-1);
    cout << "Sorted array: ";
    for(int i=0; i<vec.size(); i++){
        cout << vec[i] << " ";
    }
    cout << endl;
    return 0;
}