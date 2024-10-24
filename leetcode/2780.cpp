// 2780.合法分割的最小下标
#include <unordered_map>
using namespace std;

class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        unordered_map<int,int> mp1;
        unordered_map<int,int> mp2;
        // for(auto & it:nums) mp1[it]++;
        for(int i=0; i < nums.size(); i++){
            mp1[nums[i]]++; // 用于备份
        }
        for(int i = 0; i < nums.size(); i++){ // i从0开始遍历
            mp2[nums[i]] ++;
            if(mp2[nums[i]] * 2 > (i + 1) && (mp1[nums[i]] - mp2[nums[i]]) * 2 > (nums.size() - 1 - i))
                 return i; // 第一个符合条件的i即为最小index
        }
        return -1;
    }
};
