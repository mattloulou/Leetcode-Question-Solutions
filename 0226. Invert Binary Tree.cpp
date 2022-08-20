
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

    //v1
    // TreeNode* invertTree(TreeNode* root) {
    //     if (root == nullptr) return nullptr;
    //     TreeNode* temp = root->left;
    //     root->left = root->right;
    //     root->right = temp;
    //     if (root->left != nullptr) {
    //         invertTree(root->left);
    //     }
    //     if (root->right != nullptr) {
    //         invertTree(root->right);
    //     }
    //     return root;
    // }

    //V1
    TreeNode* invertTree(TreeNode* root) {

        //this version handles the case where root is nullptr
        if (root == nullptr) return nullptr;
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;

        //we can do the recursive call on nullptrs beacuse of the first if statement
        invertTree(root->left);
        invertTree(root->right);

        //this is only really for the first / parent recursive call
        return root;
    }
};