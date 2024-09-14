// 216.组合总和III
#include <vector>

class Solution {
private:
    vector<int> path;
    vector<vector<int>> result;
    void backTracking(int k, int n, int curSum, int start){
        if(curSum == n && path.size() == k){
            result.push_back(path);
            return;
        }
        for(int i=start; i<=9; i++){
            path.push_back(i);
            curSum+=i;
            backTracking(k, n, curSum, i+1);
            curSum-=i;
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        backTracking(k, n, 0, 1);
        return result;
    }
};