#include <vector>
#include <string>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <queue>
#include <algorithm>
#include <numeric>
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
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int, unordered_set<int>> connections;
        recursiveConnections(root, connections);

        // BFS setup
        unordered_set<int> visited;
        visited.insert(start);
        queue<int> q;
        q.push(start);
        int distance = -1;

        // while the queue is still populated:
        while(q.size()) {
            ++distance;
            const int sizeOfCurrentBatch = q.size();

            // go through current batch of elements in the queue
            for (int i = 0; i < sizeOfCurrentBatch; ++i) {
                const int currentNode = q.front();
                q.pop();

                // deal with each adjacent node
                for (const int& n : connections[currentNode]) {
                    if (!visited.count(n)) {
                        q.push(n);
                        visited.insert(n);
                    }
                }
            }
        }

        return distance;
    }

    void recursiveConnections(TreeNode* root, unordered_map<int, unordered_set<int>>& connections) {
        if (root->left) {
            connections[root->val].insert(root->left->val);
            connections[root->left->val].insert(root->val);
            recursiveConnections(root->left, connections);
        }
        if (root->right) {
            connections[root->val].insert(root->right->val);
            connections[root->right->val].insert(root->val);
            recursiveConnections(root->right, connections);
        }
    }
};

