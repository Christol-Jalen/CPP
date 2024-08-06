#include <iostream>
#include <stack>
using namespace std;

// 151.翻转字符串里的单词（栈方法）
class Solution{
public:
    string reverseWords(string s){
        stack<string> st; //创建栈储存字符
        for(int i=0; i<s.size(); i++){
            string tmp;
            while(i < s.size() && s[i] != ' '){ //一旦遇到非空格，则一直循环，直到再次遇到空格
                tmp += s[i];
                i++;
            }
            if(tmp != ""){ // 如果tmp不为空，将tmp压入栈
                st.push(tmp);
            }
        }
        string result;
        result = st.top();
        st.pop();
        while(!st.empty()){
            result += ' ';
            result += st.top();
            st.pop();
        }
        return result;
    }
};