// 438. 找到字符串中所以字符异位词
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int sLen = s.size();
        int pLen = p.size();
        if(sLen < pLen) return {};

        vector<int> sCount(26, 0);
        vector<int> pCount(26, 0);
        vector<int> result;

        // 制作p的哈希表, 并初始化s的哈希表
        for(int i=0; i<pLen; i++){
            pCount[p[i]-'a']++;
            sCount[s[i]-'a']++;
        }

        if(pCount == sCount) result.push_back(0);

        // 制作s的哈希表并维护长度为pLen的滑动窗口
        for(int i=0; i<sLen-pLen; i++){
            // 滑动窗口
            sCount[s[i]-'a']--; //窗口左端收缩
            sCount[s[i+pLen]-'a']++; //窗口右端扩张

            if(pCount == sCount) result.push_back(i+1);
        }
        return result;
    }
};