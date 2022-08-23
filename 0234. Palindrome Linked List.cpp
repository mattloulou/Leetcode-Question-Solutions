#include <string>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// O(n) complexity and O(n) space. I have no clue how to make space O(1).
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        string vals;
        while (head) {
            vals.push_back(head->val);
            head = head->next;
        }
        return vals == string(vals.rbegin(), vals.rend());
    }
};