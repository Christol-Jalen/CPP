// 213.打家劫舍II
#include <vector>
using namespace std;

class Solution {
private:
    int rob_helper(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        vector<int> dp(nums.size(), 0); // 偷n个房子可以偷到最多的钱
        // 初始化
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        // 转移方程
        for(int i=2; i<nums.size(); i++){
            dp[i] = max(nums[i]+dp[i-2], dp[i-1]);
        }

        return dp[nums.size()-1];
    }

public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];

        vector<int> tmp(nums.size()-1, 0);
        // 情况一：
        for(int i=0; i<nums.size()-1; i++){
            tmp[i] = nums[i];
        }
        int result_1 = rob_helper(tmp);
        // 情况二：
        for(int i=1; i<nums.size(); i++){
            tmp[i-1] = nums[i];
        }
        int result_2 = rob_helper(tmp);
        // 取两种情况最大值
        return max(result_1, result_2);
    }
};