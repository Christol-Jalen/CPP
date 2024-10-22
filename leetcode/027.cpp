// 27.移除元素
#include<iostream>
#include<vector>
using namespace std;

class Solution{ //双指针法（快慢指针）
public:
    int removeElement(vector<int> &nums, int &val){
        int slow = 0;
        for(int fast=0; fast<nums.size(); fast++){
            if (nums[fast] != val){
                nums[slow] = nums[fast];
                slow++;
            }
        }
        return slow;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums = {3, 2, 2, 3};
    int val = 3;
    cout << solution.removeElement(nums, val) << endl;
    return 0;
}
