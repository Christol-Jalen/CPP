// 45.跳跃游戏II
#include <vector>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() < 2) return 0;
        int curCover = 0;
        int nextCover = 0;
        int count = 0;
        
        for(int i=0; i<nums.size(); i++){
            nextCover = max(nextCover, nums[i]+i); // 只记录下一步能到最远的地方
            
            if(i == curCover){ // 当需要走一步时
                count++;
                curCover = nextCover;
                if(curCover >= nums.size()-1) break;
            }
        }
        return count;
    }
};