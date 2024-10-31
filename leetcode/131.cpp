// 131.分割回串文
#include <vector>
#include <string>
using namespace std;

class Solution {
private:
    vector<vector<string>> result;
    vector<string> path;
    bool isLoop(string s){
        int left = 0;
        int right = s.size()-1;
        while(left < right){
            if(s[left] != s[right]) return false;
            left++;
            right--;
        }
        return true;
    }

    void backTrack(string s, int startIndex){
        if(startIndex == s.size()){
            result.push_back(path);
            return;
        }
        for(int i=startIndex; i<s.size(); i++){
            string tmp = s.substr(startIndex, i - startIndex + 1); // substr()用于分割字符串
            if(isLoop(tmp)){ // 是回串文
                path.push_back(tmp);
            }
            else continue; // 不是回串文

            backTrack(s, i+1); // 寻找i+1为起始位置的子串
            path.pop_back();
        }
    }

public:
    vector<vector<string>> partition(string s) {
        backTrack(s, 0);
        return result;
    }
};