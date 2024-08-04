#include <iostream>
#include <unordered_map>
using namespace std;

class Solution { // 使用unordered map
public:
    bool isAnagram(string& s, string& t) {
        if(s.size() != t.size()){
            return false;
        }
        // 创建map
        unordered_map<char, int> count;
        // 向map中添加s中的字符
        for(char c : s){
            count[c]++;
        }
        // 用t中字符抵消
        for(char c : t){
            count[c]--;
            if(count[c] < 0) return false; //t中的这个字符在s中不存在
        }
        for(pair<char, int> p : count){
            if(p.second != 0){
                return false;
            }
        }
        return true;
    }
};

class Solution_2 { // 使用数组
public:
    bool isAnagram(string& s, string& t) {
        int record[26] = {0};
        for (int i = 0; i < s.size(); i++) {
            // 并不需要记住字符a的ASCII，只要求出一个相对数值就可以了
            record[s[i] - 'a']++;
        }
        for (int i = 0; i < t.size(); i++) {
            record[t[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if (record[i] != 0) {
                // record数组如果有的元素不为零0，说明字符串s和t 一定是谁多了字符或者谁少了字符。
                return false;
            }
        }
        // record数组所有元素都为零0，说明字符串s和t是字母异位词
        return true;
    }
};

int main(){
    
    Solution solution;

    string s = "anagram";
    string t = "nagaram";

    cout << solution.isAnagram(s, t) << endl;

    return 0;
}