// 63.不同路径II
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(); // number of rows
        int n = obstacleGrid[0].size(); // number of coloumns
        if(obstacleGrid[0][0]==1 || obstacleGrid[m-1][n-1]==1) return 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        // Initialise
        for(int i=0; i<m && obstacleGrid[i][0]!=1; i++) dp[i][0] = 1;
        for(int j=0; j<n && obstacleGrid[0][j]!=1; j++) dp[0][j] = 1;
        // Planning
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                if (obstacleGrid[i][j]==1) continue; // 遇到障碍物，跳过计算！
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};