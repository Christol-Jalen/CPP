// 746.使用最小花费爬楼梯
#include <vector>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        if(cost.size()== 2) return min(cost[0], cost[1]);
        vector<int> dp(cost.size()); // dp[i]表示爬到第i级台阶的最小花费
        dp[0] = cost[0];
        dp[1] = cost[1];
        for(int i=2; i<cost.size(); i++){
            dp[i] = cost[i] + min(dp[i-1], dp[i-2]);
        }
        return min(dp[cost.size()-1], dp[cost.size()-2]); // 返回dp最后两个值中的较小值
    }
};