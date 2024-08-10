// ref: https://www.nowcoder.com/practice/61cfbb2e62104bc8aa3da5d44d38a6ef?tpId=182&tqId=34306&rp=1&ru=/exam/oj&qru=/exam/oj&sourceUrl=%2Fexam%2Foj%3Fpage%3D1%26tab%3DSQL%25E7%25AF%2587%26topicId%3D182&difficulty=undefined&judgeStatus=undefined&tags=&title=
// 动态规划


#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int minBags(int n) {
    if (n < 6) return -1;  // 如果少于6个苹果，直接返回-1，因为无法买到。
    vector<int> dp(n + 1, INT_MAX);  
    dp[6] = 1; // 初始化6
    if (n>=8) dp[8] = 1; // 初始化8
    for(int i=9; i<n+1; i++){
        if(dp[i-6] != INT_MAX){ // Example: i = 12
            dp[i] = min(dp[i], dp[i-6]+1); 
            // dp[i] = dp[i-6]+1; // （也可以这样简化）
        }
        if(i>=8 && dp[i-8] != INT_MAX){ // Example: i = 14
            dp[i] = min(dp[i], dp[i-8]+1);
            // dp[i] =  dp[i-8]+1; // （也可以这样简化）
        }
    }
    return dp[n] == INT_MAX ? -1 : dp[n];
}

int main() {
    int n;
    cin >> n;
    cout << minBags(n) << endl;
    return 0;
}