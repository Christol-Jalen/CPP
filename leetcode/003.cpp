// 003.无重复字符的最长子串
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s=="") return 0;
        unordered_set<char> letter_set;
        int start = 0;
        int result = 1;
        for(int i=0; i<s.size(); i++){
            while(letter_set.count(s[i]) > 0){ // 遇到重复（这里必须用while，不能用if，例子：abba）
                result = max(result, i-start); // 记录最大答案
                letter_set.erase(s[start]);
                start++; // 窗口滑动
            }
            letter_set.insert(s[i]);
        }
        result = max(result, (int)s.size()-start); // 最后一个子串为最长的情况
        return result;
    }
};