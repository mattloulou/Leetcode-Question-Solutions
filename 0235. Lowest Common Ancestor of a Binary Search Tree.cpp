#include <vector> 
using namespace std;
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
/* this solution uses DFS, and passes the example cases, but gets TLE.
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* lca = root;
        while (true) {
            if (DFS(root->left, p, q, false, false)) {
                lca = root->left;
            } else if (DFS(root->right, p, q, false, false)) {
                lca = root->right;
            } else {
                return lca;
            }
        }

    }

    bool DFS(TreeNode* root, TreeNode* p, TreeNode* q, bool found_first, bool found_second) {
        if (found_first && found_second) {
            return true;
        } else if (root == nullptr) {
            return false;
        } else if (root == p) {
            return DFS(root->left, p, q, true, found_second) || DFS(root->right, p, q, true, found_second);
        } else if (root == q) {
            return DFS(root->left, p, q, found_first, true) || DFS(root->right, p, q, found_first, true);
        } else {
            return DFS(root->left, p, q, found_first, found_second) || DFS(root->right, p, q, found_first, found_second);
        }
        
    }
}; */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        //first, find the ancestory of the two nodes.
        vector<TreeNode*> ancestory1;
        vector<TreeNode*> ancestory2;

        TraceAncestory(root, p, ancestory1);
        TraceAncestory(root, q, ancestory2);

        //now I must find the closest common ancestor
        for (int i = ancestory1.size() - 1; i >= 0; --i) {
            for (int j = ancestory2.size() - 1; j >= 0; --j) {
                if (ancestory1.at(i) == ancestory2.at(j)) return ancestory1.at(i);
            }
        }

        return root; //this is just for compiler issues

    }

    //this populates the given ancestory vector with the lineage of nodes from the root to the target node
    void TraceAncestory(TreeNode* root, TreeNode* target, vector<TreeNode*>& ancestory) {

        //always add to the ancestory each step of the way
        ancestory.push_back(root);
        if (root == target) return;

        //take advantage of the BST representation invariant
        if (root->val > target->val) {
            TraceAncestory(root->left, target, ancestory);
        } else {
            TraceAncestory(root->right, target, ancestory);
        }

        //NOTE: there is no need to consider nullptr cases because target is always guaranteed to be a descendant (or the same) as the real root of this tree.
    }
};