// 46.全排列
#include <vector>
using namespace std;

class Solution {
private:
    vector<int> path;
    vector<vector<int>> result;
    void backTracking(vector<int>& vec, int index, int len){
        if(index == len){
            result.push_back(vec);
            return;
        }
        for(int i=index; i<len; i++){
            swap(vec[i], vec[index]);
            index += 1;
            backTracking(vec, index, len);
            index -= 1;
            swap(vec[i], vec[index]);
            
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        backTracking(nums, 0, nums.size());
        return result;
    }
};