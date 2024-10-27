// 139.单词拆分
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> word_set; // 换用set储存字典，因为set可以用find（或count）
        for(string word : wordDict){
            word_set.insert(word);
        }
        vector<bool> dp(s.size()+1, false); // dp[i]表示前i个字母能否由set中的单词拼接成（true/false）
        dp[0] = true;
        for(int i=1; i<=s.size(); i++){
            for(int j=0; j<i; j++){ // j是分割点
                if(dp[j] && word_set.find(s.substr(j, i-j)) != word_set.end()){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};