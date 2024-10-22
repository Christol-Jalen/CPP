// 77.组合
#include <iostream>
using namespace std;

class Solution {
private:
    vector<int> path;
    vector<vector<int>> result;
public:
    void backTracking(int n, int k, int startIndex){
        if(path.size()==k){
            result.push_back(path);
            return;
        }
        for(int i=startIndex; i<=n; i++){ //注意这里终止条件是<=
            path.push_back(i);
            backTracking(n, k, i+1);
            path.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        path.clear();
        result.clear();
        backTracking(n, k, 1);
        return result;
    }
};