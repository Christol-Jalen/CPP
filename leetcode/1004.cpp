// 1004.最大连续1的个数III
#include <algorithm>
using namespace std;


class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ans = 0, left = 0, count0 = 0;
        for(int right = 0; right < nums.size(); right++){
            count0 += 1 - nums[right]; // 统计0的个数
            while(count0 > k){
                count0 -= 1 - nums[left];
                left++;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};