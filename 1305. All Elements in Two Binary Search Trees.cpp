//Good solution:
// https://leetcode.com/problems/all-elements-in-two-binary-search-trees/discuss/464073/C++-One-Pass-Traversal


#include <vector>
#include <algorithm>
using namespace std;
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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) 
    {
        //Algorithm:
        //collect all node values from tree1 and tree2, then sort it.
        vector<int> answer;
        collectAllBSTNodeValues(root1, answer);
        collectAllBSTNodeValues(root2, answer);
        sort(answer.begin(), answer.end());
        return answer;
    }

    //this just adds all values from root + root's descendents into node_values.
    void collectAllBSTNodeValues(TreeNode*& root, vector<int>& node_values) 
    {
        if (root == nullptr) return;
        node_values.push_back(root->val);
        collectAllBSTNodeValues(root->left, node_values);
        collectAllBSTNodeValues(root->right, node_values);
    }
};