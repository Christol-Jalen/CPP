// 46.全排列
#include <vector>
using namespace std;

class Solution1 { // 标记法
private:
    vector<int> path;
    vector<vector<int>> result;
    void backTrack(vector<int> nums, vector<int> used){
        if(path.size() == nums.size()){
            result.push_back(path);
            return;
        }

        for(int i=0; i<nums.size(); i++){
            if(used[i] == true) continue; // 此数已用
            used[i] = true;
            path.push_back(nums[i]);
            backTrack(nums, used);
            used[i] = false;
            path.pop_back();
        }
    }
    
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> used(nums.size(), 0); // 标记
        backTrack(nums, used);
        return result;
    }
};

// =====================================================

class Solution2 { // 交换法
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