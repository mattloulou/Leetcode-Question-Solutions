#include <vector>
#include <queue>
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

//V1 recursive method
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> solution;
        recursiveAddNode(solution, root, 0);
        return solution;
    }

    void recursiveAddNode(vector<vector<int>>& solution, TreeNode*& root, int depth) {

        if (root == nullptr) return;

        //check if this depth has the index in solution created.
        if (solution.size() <= depth) { //if the size is not strictly greater than depth
            solution.push_back(vector<int>());
        }
        solution[depth].push_back(root->val);
        recursiveAddNode(solution, root->left, depth+1);
        recursiveAddNode(solution, root->right, depth+1);
    }
};

//V2 Queue (better?) (no recursion). Source: https://leetcode.com/problems/binary-tree-level-order-traversal/discuss/33443/C++-solution-using-only-one-queue-use-a-marker-NULL/666197
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> solution;
        if (root == nullptr) return solution;
        queue<TreeNode*> q;
        q.push(root);

        //while the current level still has nodes left
        while (!q.empty()) {
            int level_size = q.size();
            vector<int> current_level(level_size);
            for (int i = 0; i < level_size; ++i) {
                TreeNode* current_node = q.front();
                q.pop(); 
                current_level[i] = current_node->val;
                if (current_node->left != nullptr) q.emplace(current_node->left);
                if (current_node->right != nullptr) q.emplace(current_node->right);
            }
            solution.push_back(current_level);
            // current_level.clear(); //MISTAKE: no need to clear it because I remake it each loop lol
        }
        return solution;
    }
};