// 283.移动零
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    void moveZeroes(vector<int>& nums) {
    
        int left = 0, right = 0;
        while(right<nums.size()){
            if(nums[right] != 0){ // 如果nums[right] != 0
                swap(nums[left], nums[right]); // 则将left与right互换（相当于将0向右移）
                left++;
            }
            right++;
        }
    }
};