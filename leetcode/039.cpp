// 39.组合总和
#include <vector>
using namespace std;

class Solution {
private:
    vector<int> path;
    vector<vector<int>> result;

    void backTracking(vector<int>& candidates, int target, int start, int sum){
        if(sum > target) return;
        if(sum == target){
            result.push_back(path);
            return;
        }
        for(int i=start; i<candidates.size(); i++){
            sum += candidates[i];
            path.push_back(candidates[i]);
            backTracking(candidates, target, i, sum);
            sum -= candidates[i];
            path.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backTracking(candidates, target, 0, 0);
        return result;
    }
};