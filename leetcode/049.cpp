#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hash_map;
        for(int i=0; i<strs.size(); i++){
            string key = strs[i];
            sort(key.begin(), key.end()); // 排序，这样异位词都一样了，可以用来当作map的键
            hash_map[key].push_back(strs[i]);
        }
        vector<vector<string>> result;
        // 多学习一下遍历map的写法！
        for(auto it = hash_map.begin(); it != hash_map.end(); it++){
            result.push_back(it->second);
        }
        return result;

    }
};