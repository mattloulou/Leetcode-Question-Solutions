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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        //this will be a constant pointer to the answer (head of the list). However, the first node is just a placeholder
        ListNode* const answer = new ListNode{}; 

        //this will be a pointer to the current node we are working with.
        ListNode* current = answer; 
        int carry_over = 0;

        //keep looping while there is some value that must still be summed.
        while (l1 != nullptr || l2 != nullptr || carry_over != 0) {
            int l1_val = (l1 == nullptr) ? 0: l1->val;
            int l2_val = (l2 == nullptr) ? 0: l2->val;
            int sum = l1_val + l2_val + carry_over;  //this value of sum will be some number 0-19 based on the current digits and the previous carryover
            
            //if the sum requires more than 2 digits, take the ten's place off as the carryover for the next node
            if (sum >= 10) {
                carry_over = 1;
                sum -= 10;
            } else {
                carry_over = 0;
            }
            
            //create a new node and add our sum to it.
            current->next = new ListNode{sum};
            current = current->next;

            //update the nodes to go to the next one
            l1 = (l1 == nullptr) ? nullptr: l1->next;
            l2 = (l2 == nullptr) ? nullptr: l2->next;
        }
    
        //we return the next node because the one answer points to is just a placeholder.
        return answer->next;
    }
};