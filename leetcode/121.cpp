//121.股票买卖的最佳时机
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // dp[0][i]表示第i天持有该股票所拥有的最高价值(买该股票花的最少的钱)
        // dp[1][i]表示第i天不持有该股票所拥有的最高价值（卖该股票赚的最多的钱）
        vector<vector<int>> dp(2, vector<int>(prices.size())); // 2行n列
        dp[0][0] = - prices[0];
        dp[1][0] = 0;
        for(int i=1; i<prices.size(); i++){
            dp[0][i] = max(dp[0][i-1], -prices[i]);
            dp[1][i] = max(dp[0][i-1]+prices[i], dp[1][i-1]);
        }

        return dp[1][prices.size()-1];

    }
};