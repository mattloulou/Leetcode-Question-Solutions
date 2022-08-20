using namespace std;
#include <unordered_set>

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//V1
// class Solution {
// public:
//     bool hasCycle(ListNode *head) {
//         unordered_set<ListNode*> traversed;
//         ListNode* current = head;
//         while (current != nullptr) {
//             if (traversed.count(current)) {
//                 return true;
//             }
//             traversed.insert(current);
//             current = current->next;
//         }
//         return false;
//     }
// };

//V2 (concept from online)
class Solution{
public:
    bool hasCycle(ListNode* head) {
        if (head == nullptr) return false; //empty
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) return true;
        }
        return false;
    }
};