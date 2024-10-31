// 53.最大子序列和
using namespace std;

class Solution1 { // kadane算法
public:
    int maxSubArray(vector<int>& nums) {
        int gloMax = nums[0];
        int curMax = nums[0];
        for(int i=1; i<nums.size(); i++){
            curMax = max(nums[i], curMax + nums[i]);
            gloMax = max(gloMax, curMax);
        }

        return gloMax;
    }
};


class Solution2 { // 普通算法（原理和kadane算法一样）
public:
    int maxSubArray(vector<int>& nums) {
        int curSum = 0;
        int gloMax = INT_MIN;
        for(int i=0; i<nums.size(); i++){
            curSum += nums[i];
            gloMax = max(gloMax, curSum);
            if(curSum <= 0){
                curSum = 0;
            }
        }
        return gloMax;
    }
};