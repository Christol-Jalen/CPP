// 144.二叉树的前序遍历
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {};
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 二叉树的前序遍历

class Solution1 { // 递归法
public:
    void traversal(TreeNode* cur, vector<int>& result){ //这里result必须填地址，因为递归方程是void类型
        if(cur==nullptr) return;
        result.push_back(cur->val);
        traversal(cur->left, result);
        traversal(cur->right, result);
    }

    vector<int> preorder_traversal(TreeNode* root){
        vector<int> result;
        traversal(root, result);
        return result;
    }

};

class Solution2 { // 迭代法
public:
    vector<int> preorder_traversal(TreeNode* root){
        stack<TreeNode*> st;
        vector<int> result;
        if(root==nullptr) return result;
        st.push(root);
        while(!st.empty()){
            TreeNode* cur = st.top();
            st.pop();
            result.push_back(cur->val);
            if(cur->right) st.push(cur->right);
            if(cur->left) st.push(cur->left);
        }
        return result;
    }

};

int main() {
    // 构建测试用的二叉树
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    // 创建Solution实例
    Solution2 solution;
    vector<int> result = solution.preorder_traversal(root);

    // 预期的前序遍历结果
    vector<int> expected = {1, 2, 4, 5, 3};

    // 验证结果是否正确
    bool is_correct = (result == expected);
    cout << "Test Result: " << (is_correct ? "PASS" : "FAIL") << endl;

    // 输出实际结果
    cout << "Traversal Output: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}