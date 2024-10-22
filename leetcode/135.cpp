// 分发糖果
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> candyVic(ratings.size(), 1);
        for(int i=1; i<ratings.size(); i++){
            if(ratings[i] > ratings[i-1]) {
                candyVic[i] = candyVic[i-1]+1;
            }
        }
        for(int i=ratings.size()-2; i>=0; i--){
            if(ratings[i] > ratings[i+1]){
                candyVic[i] = max(candyVic[i], candyVic[i+1]+1);
            }
        }
        int result = accumulate(candyVic.begin(), candyVic.end(), 0);
        return result;
    }
};
