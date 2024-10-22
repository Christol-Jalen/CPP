// 1002. 查找共用字符
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string> result;
        if (words.empty()) return result;

        int minFreq[26];
        fill(begin(minFreq), end(minFreq), INT_MAX); // 初始化全局最小频率为极大值

        // 对每个单词进行处理
        for (const auto& word : words) {
            int charFreq[26] = {0}; // 当前单词的字符频率
            for (char c : word) {
                charFreq[c - 'a']++;
            }
            // 更新全局最小频率
            for (int i = 0; i < 26; i++) {
                minFreq[i] = min(minFreq[i], charFreq[i]);
            }
        }

        // 根据全局最小频率构建结果
        for (int i = 0; i < 26; i++) {
            while (minFreq[i] > 0) {
                result.push_back(string(1, 'a' + i));
                minFreq[i]--;
            }
        }

        return result;
    }
};