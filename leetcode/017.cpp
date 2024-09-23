// 17.电话号码的字母组合
#include <vector>
using namespace std;

class Solution {
private:
    vector<string> result;
    string tmp;
    vector<string> letterMap = {
        "",    // 0
        "",    // 1
        "abc", // 2
        "def", // 3
        "ghi", // 4
        "jkl", // 5
        "mno", // 6
        "pqrs",// 7
        "tuv", // 8
        "wxyz" // 9
    };

    void backTracking(string& digits, int depth){
        if(depth == digits.size()){
            result.push_back(tmp);
            return;
        };
        
        int digit = digits[depth] - '0';
        string letters = letterMap[digit];
        for(int j=0; j<letters.size(); j++){ //循环每个数字对应的字母
            tmp += letters[j];
            backTracking(digits, depth+1); //进入下一个数字
            tmp.pop_back(); // 原来string也能push_back, pop_back
        }
        
    }

public:
    vector<string> letterCombinations(string& digits) {
        if (digits.size() == 0) {
            return result;
        }
       backTracking(digits, 0);
       return result; 
    }
};