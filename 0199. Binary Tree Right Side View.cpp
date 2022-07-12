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

// //V1 (inefficient ordering in the recursive method)
// class Solution {
// public:
//     vector<int> rightSideView(TreeNode* root) {
//         unordered_map<int,int> solution;
//         rightSideCollector(root, solution, 0);
//         vector<int> vectorSolution(static_cast<int>(solution.size()));
//         for (const pair<int,int>& p : solution) {
//             vectorSolution.at(p.first) = p.second;
//         }
//         return vectorSolution;
//     }

//     void rightSideCollector(TreeNode* root, unordered_map<int,int>& solution, int depth) {
//         if (!root) return;
//         rightSideCollector(root->left, solution, depth+1);
//         solution[depth] = root->val;
//         rightSideCollector(root->right, solution, depth+1);
//     }
// };

//V2 (avoid using a map by implementing recursive method properly)
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> solution;
        rightSideCollector(root, solution, 0);
        return solution;
    }

    void rightSideCollector(TreeNode* root, vector<int>& solution, int depth) {
        if (!root) return;
        if (depth >= solution.size()) solution.push_back(root->val);
        rightSideCollector(root->right, solution, depth+1);
        rightSideCollector(root->left, solution, depth+1);
    }
};