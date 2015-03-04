/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (!head || !head->next)   return head;
        
        ListNode *cur = head, dummy(-1), *pre = &dummy;
        dummy.next = head;
        while (cur) {
            while (cur->next && cur->next->val == pre->next->val) 
                cur = cur->next;
  
            if (pre->next == cur)
                pre = pre->next;
            else
                pre->next = cur->next;
            cur = cur->next;
        }
        return dummy.next;
    }
};
