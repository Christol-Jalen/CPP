#include "head.h"

class Solution{
//双指针法（滑动窗口）
public:
    int minSubArrayLen(int s, vector<int>& vec){
        int result = INT32_MAX;
        int sum = 0;
        int window_len = 0;
        int slow = 0;
        for(int fast = 0; fast < vec.size(); fast++){
            sum += vec[fast];
            while(sum>=s){
                sum -= vec[slow];
                window_len = fast - slow + 1;
                slow++;
                result = min(result, window_len);
            }
        }
        return result == INT32_MAX ? 0 : result;
    }
};

int main(){
    Solution solution;
    vector<int> nums = {2,3,1,2,4,3};
    int s = 7;
    cout << solution.minSubArrayLen(s, nums) << endl;
    return 0;
}