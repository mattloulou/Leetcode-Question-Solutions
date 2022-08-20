#include <vector>
using namespace std;

//Definition for a binary tree node.
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
    bool isBalanced(TreeNode* root) {
        bool is_balanced_tree = true;
        DFS(root, is_balanced_tree);
        return is_balanced_tree;
    }

    int DFS(TreeNode*& root, bool& is_balanced) { //is this even DFS? idek. I just wrote it just because lmao.

        //we already know it is bad so just get out of recursive function stack asap
        if (is_balanced == false) {
            return 0;
        }

        //making the root being nullptr the base case costs some memory but it makes the code much easier to write
        if (root == nullptr) {
            return -1; //this works out. If you give a tree with just a root, then the height will be 0.
        }
        
        //now, compare if the difference in the two branch subtrees is max 1
        const int left = DFS(root->left, is_balanced);
        const int right = DFS(root->right, is_balanced);
        if (abs(left-right) > 1) {
            is_balanced = false;
        }
        return max(left, right) + 1;
    }
};