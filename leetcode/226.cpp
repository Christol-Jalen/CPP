// 翻转二叉树
#include 'head.h'

class Solution {
public:
    void traversal(TreeNode* cur) { // 前序遍历
        if (cur == nullptr) return;

        // 交换左右子节点（这部分可以用swap库函数替代）
        // swap(cur->left, cur->right)
        TreeNode* tmp = cur->left;
        cur->left = cur->right;
        cur->right = tmp;

        // 递归翻转子树
        traversal(cur->left);
        traversal(cur->right);
    }

    TreeNode* invertTree(TreeNode* root) {
        traversal(root);
        return root;
    }
};
