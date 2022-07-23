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
    ListNode* partition(ListNode* head, int x) {
        
        // create a new node at the start to decrease the complexity of the rest of the code.
        // It will be deleted at the end.
        head = new ListNode(-1000, head);

        // we first need to find the first node   >= x.
        ListNode* nextNodeIsTarget = head;
        while (nextNodeIsTarget->next && nextNodeIsTarget->next->val < x) nextNodeIsTarget = nextNodeIsTarget->next;

        // return early if no moves have to happen
        if (!nextNodeIsTarget->next) {
            ListNode* temp = head->next;
            delete head;
            return temp;            
        }

        // now we go through the list after the node, and move all nodes less than it to before nextNodeIsTarget->next
        ListNode* traverser = nextNodeIsTarget->next;
        while (traverser->next != nullptr) {
            if (traverser->next->val < x) {
                // remove the small node past the target node
                ListNode* temp = traverser->next;
                traverser->next = temp->next;

                // put the small node in the right location
                temp->next = nextNodeIsTarget->next;
                nextNodeIsTarget->next = temp;
                nextNodeIsTarget = nextNodeIsTarget->next;
            } else {
                traverser = traverser->next;
            }
        }

        ListNode* temp = head->next;
        delete head;
        return temp;    
    }
};