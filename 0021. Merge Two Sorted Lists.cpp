
//Definition for singly-linked list.
struct ListNode{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode new_list{}; // default constructor call. Creates new stack object
        ListNode* head = &new_list;
        ListNode* current = &new_list;

        //while there are still unsorted nodes:
        while (list1 != nullptr || list2 != nullptr) {

            //case where both lists have nodes
            if (list1 != nullptr && list2 != nullptr) {
                if (list1->val < list2->val) {
                    current->next = list1;
                    list1 = list1->next;
                } else {
                    current->next = list2;
                    list2 = list2->next;
                }
            }

            //case where only the first list has nodes remaining
            else if (list1 != nullptr) {
                current->next = list1;
                list1 = list1->next;
            }

            //case where only the second list has nodes remaining
            else {
                current->next = list2;
                list2 = list2->next;
            }

            //all cycles must move current forward one.
            current = current->next;
        }
    
        //since the node head points to is just a fake node used to let us have a simple algorithm (always can do current->next),
        //and is stack allocated (so auto deletion), we return the next node.
        return head->next;
    }
};