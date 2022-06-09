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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if ((p && !q) || (!p && q)) return false; // if one is nullptr but the other isn't
        if (!p) return true; // if both are nullptr
        if (p->val != q->val) return false; // if they have different values
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};