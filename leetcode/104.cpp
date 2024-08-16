//104.二叉树的最大深度
#include 'head.h'

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution1 { // 层序遍历法
public:
    int maxDepth(TreeNode* root) {
        if(root==nullptr) return 0;
        queue<TreeNode*> que;
        int depth = 0;
        que.push(root);
        while(!que.empty()){
            int size = que.size();
            depth++;
            for(int i=0; i<size; i++){
                TreeNode* cur = que.front();
                que.pop();
                if(cur->left) que.push(cur->left);
                if(cur->right) que.push(cur->right);
            }
        }
        return depth;
    }
};

class Solution2 { // 前序遍历 + 回溯法
private:
    int result;
    void backTracking(TreeNode* node, int depth){

        result = max(depth, result); // 中 (只更新最大深度)

        if(node->left == nullptr && node->right == nullptr) return; // 终止条件

        if(node->left){
            depth++;
            backTracking(node->left, depth);
            depth--;
        }

        if(node->right){
            depth++;
            backTracking(node->right, depth);
            depth--;
        }
        return;
    }
public:
    int maxDepth(TreeNode* root) {
        result = 0;
        if (root==nullptr) return result;
        backTracking(root, 1); // root的深度是1
        return result;
    }
};