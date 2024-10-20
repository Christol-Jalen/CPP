//55.跳跃游戏
#include <vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size() < 2) return true;
        int cover = 0;
        for(int i=0; i<=cover; i++){ // 注意这里是小于等于cover
            cover = max(i+nums[i], cover);
            if (cover >= nums.size()-1) return true;
        }
        return false;
    }
};