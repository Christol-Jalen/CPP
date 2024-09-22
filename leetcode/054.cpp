// 054.螺旋矩阵
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        if(matrix.empty()) return ans;
        // 定义边界
        int up = 0;
        int down = matrix.size()-1;
        int left = 0;
        int right = matrix[0].size()-1;
        
        while(true){
            // 遍历上行
            for(int i=left; i<=right; i++) ans.push_back(matrix[up][i]);
            if(++up > down) break; // 上下边界重合，跳出循环
            // 遍历右列
            for(int i=up; i<=down; i++) ans.push_back(matrix[i][right]);
            if(--right < left) break; // 左右边界重合， 跳出循环
            //遍历下行
            for(int i=right; i>=left; i--) ans.push_back(matrix[down][i]);
            if(--down < up) break;
            //遍历左列
            for(int i=down; i>=up; i--) ans.push_back(matrix[i][left]);
            if(++left > right) break;
        }
        return ans;
    }
};