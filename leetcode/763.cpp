// 763.划分字母区间
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> result;
        vector<int> last(26, 0); // 返回当前字符最后出现的位置
        for(int i=0; i<s.size(); i++){
            last[s[i]-'a'] = i; 
        }
        int start = 0;
        int end = 0;
        for(int i=0; i<s.size(); i++){
            end = max(end, last[s[i]-'a']);
            if(i == end){
                result.push_back(end - start + 1);
                start = end + 1;
            }
        }
        return result;
    }
};