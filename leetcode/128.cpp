// 128. 最长连续序列
#include <vector>
#include <unordered_set>

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        unordered_set<int> set1;
        for(int num : nums){
            set1.insert(num);
        }
        
        int curLongest = 1;
        int gloLongest = 1;
        for(int num : set1){
            
            if (!set1.count(num - 1)) {  //优化： 只从一个连续序列的第一个数开始用while循环检查是否连续
                int curNum = num;
                curLongest = 1;

                while(set1.count(curNum+1)){
                curNum++;
                curLongest++;
                }
            }
            
            gloLongest = max(gloLongest, curLongest);
            curLongest = 1;
        }
        return gloLongest;
    }
};

