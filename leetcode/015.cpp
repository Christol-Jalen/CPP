//15.三数之和（双指针法）

#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    vector<vector<int>> threeSum(vector<int>& nums){
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        for(int i=0; i<nums.size(); i++){

            if(nums[i] > 0) break; // 剪枝： 如果三元组的第一个数字（a）大于0，则不可能组成和为0的三元组
            if(i>0 && nums[i]==nums[i-1]) continue; // 对a去重

            int left = i+1;
            int right = nums.size()-1;
            while(left<right){
                if(nums[i]+nums[left]+nums[right]>0) right--;
                else if(nums[i]+nums[left]+nums[right]<0) left++; //这里必须用else if， 因为存在right--后导致三数和<0，从而又触发left++的情况
                else{
                    result.push_back(vector<int>{nums[i], nums[left], nums[right]});
                    while(left<right && nums[left]==nums[left+1]) left++; //对b去重
                    while(left<right && nums[right]==nums[right-1]) right--; //对c去重
                    //找到答案后同时收缩双指针
                    left++;
                    right--;
                }
            }
        }
        return result;
    }
};

int main(){
    return 0;
}