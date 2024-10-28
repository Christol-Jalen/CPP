// 56.合并区间
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() == 0) return {};
        sort(intervals.begin(), intervals.end()); // 根据每个向量的第一个元素排序
        
        vector<vector<int>> merged;
        for(int i=0; i<intervals.size(); i++){
            int L = intervals[i][0];
            int R = intervals[i][1];
            // 当当前区间的左边界大于上一个区间的又边界时，(或merged为空)
            if(merged.size()==0 || merged.back()[1] < L){
                // 不需要融合，直接加入merged
                merged.push_back({L, R});
            }
            // 需要融合的情况
            else{
                merged.back()[1] = max(merged.back()[1], R);
            }
        }
        return merged;
    }
};