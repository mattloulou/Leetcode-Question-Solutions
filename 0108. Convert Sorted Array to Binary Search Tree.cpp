#include <vector>
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return recurse(nums, 0, nums.size()-1);
    }

    TreeNode* recurse(vector<int>& nums, int start, int end) {
        if (start > end) return nullptr;
        
        const int currentIndex = (start + end) / 2;
        TreeNode* current = new TreeNode(nums[currentIndex]);
        current->right = recurse(nums, currentIndex+1, end);
        current->left = recurse(nums, start, currentIndex-1);
        return current;

    }
};