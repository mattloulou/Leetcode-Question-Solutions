// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//V1 checking the representation invariant for each node. Very bad time complexity
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        bool isValid = true;
        if (root->left) {
            isValid = (largestDescendant(root->left) < root->val);
            if (!isValid) return false;
            isValid = isValid && isValidBST(root->left);
            if (!isValid) return false;
        }
        if (root->right) {
            isValid = (smallestDescendant(root->right) > root->val);
            if (!isValid) return false;
            isValid = isValid && isValidBST(root->right);
            if (!isValid) return false;
        }
        return isValid;
    }

    int largestDescendant(TreeNode* root) const {
        if (root->right == nullptr) return root->val;
        return largestDescendant(root->right);
    }

    int smallestDescendant(TreeNode* root) const {
        if (root->left == nullptr) return root->val;
        return smallestDescendant(root->left);
    }
};

//V2 flatten tree then check. better runtime. Idea from: https://leetcode.com/problems/validate-binary-search-tree/discuss/786520/General-Tree-Traversal-Problems-interview-Prep
#include <vector>
using namespace std;
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        vector<int> values;
        flattenTree(root, values);
        for (int i = 1; i < values.size(); ++i) {
            if (!(values[i] > values[i-1])) return false;
        }
        return true;
    }

    void flattenTree(TreeNode*& root, vector<int>& array) {
        if (!root) return;
        flattenTree(root->left, array);
        array.emplace_back(root->val);
        flattenTree(root->right, array);
    }
};