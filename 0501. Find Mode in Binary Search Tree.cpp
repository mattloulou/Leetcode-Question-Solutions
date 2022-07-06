#include <vector>
#include <unordered_map>
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
    vector<int> findMode(TreeNode* root) {
        unordered_map<int, int> vals; // {val, count}
        getVals(vals, root);
        vector<int> mode_vals;
        int max_frequency = 0;
        for (const pair<int,int>& p : vals) {
            if (p.second > max_frequency) {
                mode_vals.clear();
                mode_vals.push_back(p.first);
                max_frequency = p.second;
            } else if (p.second == max_frequency) {
                mode_vals.push_back(p.first);
            } 
        }
        return mode_vals;
    }

    void getVals(unordered_map<int,int>& vals, TreeNode*& root) {
        if (!root) return;
        ++vals[root->val];
        getVals(vals, root->left);
        getVals(vals, root->right);
    }
};