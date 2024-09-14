// 698.划分为k个相等的子集
#include <iostream>
#include <numeric>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
    static bool cmp(int a, int b) { // 比较函数，用于sort降序排列，这里必须使用静态函数static
        return a > b;
    }
    bool backTracking(vector<int>& nums, int k, int start, vector<int>& used, int currentSum, int target){

        if(k==0) return true; // k组都分完了，结束！

        if(currentSum == target) return backTracking(nums, k-1, 0, used, 0, target); // 这一步不能直接返回true，需要开启新的一轮

        for(int i=start; i<nums.size(); i++){
            if(!used[i] && nums[i]+currentSum <= target){
                used[i] = true;

                if(backTracking(nums, k, i+1, used, currentSum+nums[i], target)) return true;
                used[i] = false; // 回溯
            } 
        }
        return false;
    }
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % k != 0) return false; // 如果不能整除，则一定不能分成k个相等的子集
        int target = sum / k;
        vector<int> used(nums.size(), 0); // 0 代表 false
        sort(nums.begin(), nums.end(), cmp); // 降序排列，先分配大的数字，这样可以优化代码
        return backTracking(nums, k, 0, used, 0, target);
    }
};