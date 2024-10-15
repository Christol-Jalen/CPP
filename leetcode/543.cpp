//543.二叉树的直径
#include "head"
using namespace std;


class Solution {
private:
    int ans = 1; // 记录路径节点总数
    int dfs(TreeNode* node){
        if(node == nullptr) return 0;
        int L = dfs(node->left);
        int R = dfs(node->right);
        ans = max(ans, L+R+1);
        return max(L,R) + 1; // +1是这个节点本身
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return ans-1; // 直径是路径节点总数-1
    }
};