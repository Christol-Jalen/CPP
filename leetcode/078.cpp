// 78.子集（回溯法）
#include <vector>
using namespace std;

class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;
    void backTracking(vector<int>& nums, vector<int>& path, int index){
        result.push_back(path);
        for(int i=index; i<nums.size(); i++){
            path.push_back(nums[i]);
            backTracking(nums, path, i+1);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        backTracking(nums, path, 0);
        return result;
    }
};

/*
通过上述步骤，最终 result 包含了所有可能的子集，按照添加的时间顺序如下：

	1.	[] （空集）
	2.	[1]
	3.	[1, 2]
	4.	[1, 2, 3]
	5.	[1, 3]
	6.	[2]
	7.	[2, 3]
	8.	[3]
*/