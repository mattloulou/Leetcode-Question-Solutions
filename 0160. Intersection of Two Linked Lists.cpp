#include <unordered_set>
using namespace std;
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> visited;
        while (headA || headB) {
            if (headA) {
                if (visited.count(headA)) return headA;
                visited.insert(headA);
                headA = headA->next;
            }
            if (headB) {
                if (visited.count(headB)) return headB;
                visited.insert(headB);
                headB = headB->next;
            }
        }
        return nullptr;
    }
};


// V2 (much faster and much better memory) from https://leetcode.com/problems/intersection-of-two-linked-lists/discuss/49789/My-accepted-simple-and-shortest-C++-code-with-comments-explaining-the-algorithm.-Any-comments-or-improvements/50127
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* p1 = headA;
        ListNode* p2 = headB;

        // 1. basically, if both lists intersect after the same number of nodes, then they will eventually become equal at the same time, which then exits the while loop
        // 2. if both lists intersect but after a different distance from headA vs headB, then basically once a pointer reaches the end of the list, it starts at the head of the other list. This will then cause both pointers to meet up at 
        // the intersection point on the second run through.
        // 3. In the third case where they don't intersect, then after their first swap, at the end of their second traversal of their lists they will both be nullptr, which will then be returned.
        while (p1 != p2) {
            p1 = (p1) ? p1->next: headB;
            p2 = (p2) ? p2->next: headA;
        }
        return p1;
    }
};