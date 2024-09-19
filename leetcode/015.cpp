//15.三数之和（双指针法）

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end()); //数组升序排序

        for(int i=0; i<nums.size(); i++){
            if(nums[i]>0) break; // 如果第一个数已经大于0，则不可能再达到三数和为0
            if(i>0 && nums[i]==nums[i-1]) continue; // 对第一个元素去重
            int left = i+1;
            int right = nums.size()-1;

            while(left < right){
                
                // 如果三数和大于0，则右指针向左移动
                if(nums[i]+nums[left]+nums[right]>0) right--;
                // 如果三数和小于0，则左指针向右移动
                else if(nums[i]+nums[left]+nums[right]<0) left++;
                // 三数和等于0
                else{
                    result.push_back({nums[i], nums[left], nums[right]});
                    // 去重复（三元组内部元素可以重复，但是三元组不能重复）
                    while(left < right && nums[left]==nums[left+1]) left++;
                    while(left < right && nums[right]==nums[right-1]) right--;
                    right--;
                    left++;
                }
            }
        }
        return result;
    }
};

int main(){
    return 0;
}