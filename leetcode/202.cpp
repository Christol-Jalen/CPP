// 202.快乐数
#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
private:
    int squareSum(int n){
        int square_sum = 0;
        while(n){
            int bit = n % 10;
            int square = bit * bit;
            square_sum += square;
            n /= 10;
        }
        return square_sum;
    }
public:
    bool isHappy(int n) {
        unordered_set<int> sum_set;
        int next = squareSum(n); // 创建变量储存计算值
        while(sum_set.find(next) == sum_set.end()){
            if(next == 1) return true;
            sum_set.insert(next);
            next = squareSum(next);
        }
        return false;
    }
};