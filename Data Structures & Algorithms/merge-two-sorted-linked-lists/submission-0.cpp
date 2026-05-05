/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // 1. Create a dummy node to act as the safe starting point
        ListNode dummy(0);
        ListNode* tail = &dummy;
        
        // 2. Loop while BOTH lists still have nodes to compare
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }
            // Move the tail forward after stitching a node
            tail = tail->next; 
        }
        
        // 3. One list is empty, just append the rest of the other list!
        if (list1 != nullptr) {
            tail->next = list1;
        } else {
            tail->next = list2;
        }
        
        // 4. Return the merged list, skipping the dummy node
        return dummy.next;
    }
};
