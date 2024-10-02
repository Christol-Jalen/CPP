// 22.括号生成
#include <vector>
#include <stack>
#include <string>
using namespace std;

class Solution {
private:
    vector<string> result;
    string sample;

    bool valid(string brackets){
        // 20. 有效的括号
            stack<char> st;
            for(char b : brackets){
                if(b=='(') st.push(')');
                else if(st.empty() || st.top() != b) return false;
                else st.pop();
            }
            return st.empty();
        }
        void generateAll(int n){
            if(sample.size() >= 2*n){
                if(valid(sample)){
                    result.push_back(sample);
                }
                return;
            }
            // 回溯
            sample += '(';
            generateAll(n);
            sample.pop_back();
            sample += ')';
            generateAll(n);
            sample.pop_back();
        }
public:
    vector<string> generateParenthesis(int n) {
        generateAll(n);
        return result;
    }
};