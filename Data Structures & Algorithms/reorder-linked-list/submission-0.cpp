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
    ListNode* middle(ListNode* temp){
        ListNode* slow = temp;
        ListNode* fast = temp;

        while(fast != nullptr && fast->next != nullptr){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

    ListNode* reverse(ListNode* temp){
        ListNode* prev = nullptr;
        ListNode* curr = temp;
        while(curr != nullptr){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    void reorderList(ListNode* head) {
        if(head == nullptr || head->next == nullptr){
            return;
        }
        ListNode* mid = middle(head);
        ListNode* list2 = reverse(mid->next);
        mid->next = nullptr;
        ListNode* list1 = head;

        while(list2 != nullptr){
            ListNode* temp1 = list1->next;
            ListNode* temp2 = list2->next;

            list1->next = list2;
            list2->next = temp1;

            list1 = temp1;
            list2 = temp2;
        }

    }
};
