// 344. 反转字符串
#include <iostream>
#include <algorithm>
using namespace std;

class Solution { //利用库函数reverse
public:
    void reverseString(vector<char>& s) {
        reverse(s.begin(), s.end());
    }
};

class Solution_1 { //不用库函数
public:
    void reverseString(vector<char>& s){
        for(int i=0, j=s.size()-1; i<s.size()/2; i++, j--){
            swap(s[i], s[j]);
        }
    }
};