// 98.验证二叉搜索树
using namespace std;

class Solution {
private:
    bool dfs(TreeNode* node, long minVal, long maxVal){
        if(node == nullptr) return true; // 空节点有效
        // 当前节点的值必须大于minVal，且小于maxVal
        if(node->val <= minVal || node->val >= maxVal){
            return false;
        }
        // 递归检查左子树和右子树，更新范围
        return dfs(node->left, minVal, node->val) && 
               dfs(node->right, node->val, maxVal);
    }
public:
    bool isValidBST(TreeNode* root) {
        // 初始范围设为(-infinity, +infinity)
        return dfs(root, LONG_MIN, LONG_MAX);
    }
};