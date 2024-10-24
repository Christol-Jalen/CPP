// 1004.最大连续1的个数III
#include <algorithm>
using namespace std;

// ================方法一：滑动窗口================
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ans = 0, left = 0, count0 = 0;
        for(int right = 0; right < nums.size(); right++){
            count0 += 1 - nums[right]; // 统计0的个数
            while(count0 > k){
                count0 -= 1 - nums[left];
                left++;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};


// ================方法二：回溯法================
#include <vector>

void backtracking(vector<int> &a, int k, int &result, int flipNum) {
  if (flipNum == k) {
    // 回溯
    int length = 0;
    int n = a.size();
    for (int i = 0; i < n; ++ i) {
      if (a[i] == 1) {
        length += 1;
      } else if (a[i] == 0) {
        result = max(result, length);
        length = 0;
      }
    }
    return;
  }
  int n = a.size();
  for (int i = 0; i < n; ++ i) {
    if (a[i] == 0) {
      a[i] = 1;
      flipNum += 1;
      backtracking(a, k, result, flipNum);
      flipNum -= 1;
      a[i] = 0;
    }
  }
} 

int main() {
  vector<int> a = {0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1};
  int k = 3;
  int result = 0;
  backtracking(a, k, result, 0);
  cout << result << endl;
}