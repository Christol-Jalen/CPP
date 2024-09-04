// 042.接雨水
#include <iostream>
using namespace std;


class Solution { // 暴力法（双指针）
public:
    int trap(vector<int>& height) {
        int sum = 0;
        for(int i=0; i<height.size(); i++){
            if(i==0 || i==height.size()-1) continue;
            int left_h = height[i];
            int right_h = height[i];
            for(int left=i-1; left>=0; left--){
                left_h = max(left_h, height[left]);
            }
            for(int right=i+1; right<height.size(); right++){
                right_h = max(right_h, height[right]);
            }
            int h = min(left_h, right_h) - height[i];
            if(h>0) sum += h;
        }
        return sum;
    }
};