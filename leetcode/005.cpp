// 5.Z字型变换
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows < 2) return s;

        vector<string> mat(numRows);
        int flag = -1; // 关键flag
        int i = 0; // 表示当前行数
        for(char c : s){
            mat[i] += c;
            if(i == 0 || i == numRows-1){
                flag *= -1; // 如果到了两端，翻转flag
            }
            i += flag;
        }
        // 输出结果
        string result;
        for(string row : mat){
            result += row;
        }
        return result;
    }
};