// 70. 爬楼梯
#include <vector>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if(n <= 2) return n;
        
        vector<int> dp(n+1); // 代表爬到每级台阶拥有的方法
        dp[0] = 0; // 0级台阶无意义
        dp[1] = 1;
        dp[2] = 2;
        for(int i=3; i<n+1; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};