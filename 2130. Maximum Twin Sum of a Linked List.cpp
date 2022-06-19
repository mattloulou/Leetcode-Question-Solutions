#include <vector>
using namespace std;
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    int pairSum(ListNode* head) {
        vector<int> values;
        while (head) {
            values.push_back(head->val);
            head = head->next;
        }

        int max_pair = 0;
        for (int i = 0; i < values.size()/2; ++i) {
            max_pair = max(max_pair, values[i] + values[values.size()-1-i]);
        }

        return max_pair;
    }
};