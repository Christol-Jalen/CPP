#include "head.h"

class Solution_1{
    // 使用sort库函数
    public:
    vector<int> sortedSquares(vector<int>& A){
        for(int i=0; i < A.size(); i++){
            A[i] *= A[i];
        }
        sort(A.begin(), A.end());
        return A;
    }
};

class Solution_2{
    //使用冒泡排序
    private:
    vector<int> bubble_sort(vector<int>& vec){
        int length = vec.size();
        for(int i = 0; i < length-1; i++){ //
            for(int j = 0; j<length-1-i; j++){ 
                // j每轮循环结束后，都会把最大的数放在循环末尾，因此每次循环到j<length-1-i就可以
                if(vec[j]>vec[j+1]){
                    swap(vec[j], vec[j+1]); // 如果顺序错误，交换位置
                }
            }
        }
        return vec;
    }
    public:
    vector<int> sortedSquares(vector<int>& A){
        for(int i=0; i < A.size(); i++){
            A[i] *= A[i];
        }
        bubble_sort(A);
        return A;
    }
};


int main(){
    Solution_2 solution;
    vector<int> A = {-4, -1, 0, 3, 10};
    solution.sortedSquares(A);
    for(int i=0; i<A.size(); i++){
        cout << A[i] << " ";
    }
    cout << endl;
    return 0;
}