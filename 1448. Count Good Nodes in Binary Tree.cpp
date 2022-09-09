#include <algorithm>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int goodNodes(TreeNode* root) {
        int result = 0;
        dfs(root, result, root->val);
        return result;
    }

    void dfs(const TreeNode* const node, int& result, const int currentMax) {
        if (!node) return;
        result += node->val >= currentMax;
        const int newMax = std::max(currentMax, node->val);
        dfs(node->left, result, newMax);
        dfs(node->right, result, newMax);
    }
};