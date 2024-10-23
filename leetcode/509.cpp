// 509.斐波那契数
#include <vector>
using namespace std;

class Solution {
public:
    int fib(int n) {
        if(n==0) return 0;
        if(n==1) return 1;
        vector<int> dp(n+1); // 注意dp数组的大小是n+1， 不是n
        dp[0] = 0;
        dp[1] = 1;
        for(int i=2; i<n+1; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
    
        return dp[n];
    }
};