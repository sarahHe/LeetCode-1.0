/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 2015.5.30 update
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *p = head;
        while (p && p->next) {
            while (p && p->next && p->val == p->next->val)
                p->next = p->next->next;
            p = p->next;
        }
        return head;
    }
};
