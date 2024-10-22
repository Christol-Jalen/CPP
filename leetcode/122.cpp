// 122.买卖股票的最佳时机II
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // dp[0][i]表示第i天考虑买股票所可以拥有的最多现金。
        // dp[1][i]表示第i天考虑卖股票所可以拥有的最多现金
        vector<vector<int>> dp(2, vector<int>(prices.size())); // 2行n列
        dp[0][0] = -prices[0];
        dp[1][0] = 0;
        for(int i=1; i<prices.size(); i++){
            dp[0][i] = max(dp[0][i-1], -prices[i]+dp[1][i-1]);
            dp[1][i] = max(dp[0][i-1]+prices[i], dp[1][i-1]);
        }
        return dp[1][prices.size()-1];
    }
};