// 704. 二分查找
#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    int search(vector<int> &nums, int &target){
        int left = 0;
        int right = nums.size()-1;
        while(left <= right){
            int middle = left + (right-left)/2;
            if(nums[middle] < target) left = middle+1;
            else if(nums[middle] > target) right = middle-1;
            else return middle;
        }
    return -1;
    }
};


int main(){
    Solution solution;
    vector<int> nums = {-1, 0, 3, 5, 9, 12};
    int target = 9;
    cout << solution.search(nums, target) << endl;
    return 0;
}