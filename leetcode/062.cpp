// 62.不同路径
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        // dp[m][n]表示去(m,n)点的路径数量
        vector<vector<int>> dp(m, vector<int>(n,0));
        // 初始化
        for(int i=0; i<m; i++) dp[i][0] = 1;
        for(int j=0; j<n; j++) dp[0][j] = 1;
        // 状态转移
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};