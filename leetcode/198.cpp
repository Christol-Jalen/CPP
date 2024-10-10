// 198.打家劫舍
#include <vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
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
};