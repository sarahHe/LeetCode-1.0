//Sort a linked list using insertion sort.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 2015.6.1 update
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode dummy(-1);
        while (head) {
            ListNode *pre = &dummy;
            while (pre->next && pre->next->val <= head->val) 
                pre = pre->next;
            
            ListNode *t = head->next; // not *t = head
            head->next = pre->next;
            pre->next = head;
            head = t; // not head = t->next;
        }
        return dummy.next;
    }
};
