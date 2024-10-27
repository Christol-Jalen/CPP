// 1005.K次取反后最大化的数组和
#include <algorithm>
#include <numeric> 
#include <vector>

class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] < 0 && k > 0) {
                nums[i] = -nums[i];
                k--;
            }
        }
        // 如果还剩奇数次反转，反转最小元素
        // 注意，优先把所有负数都取反后，再考虑下面这一步
        if (k % 2 == 1) {
            sort(nums.begin(), nums.end()); // 确保最小的元素在前
            nums[0] = -nums[0];
        }
        return accumulate(nums.begin(), nums.end(), 0);
    }
};