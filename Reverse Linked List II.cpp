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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if (!head || !head->next || m >= n)   return head;
        
        ListNode *pre = head, *cur = head;
        int i = 1;
        while (i < m && cur) {
            pre = cur;
            cur = cur->next;
            i++;
        }
        if (!cur)   return head;
        
        ListNode *p = cur->next;
        while (i < n && p) {
            cur->next = p->next;
            if (m == 1) {
                p->next = head;
                head = p;
            }
            else {
                p->next = pre->next;
                pre->next = p;
            }
            p = cur->next;
            i++;
        }
        return head;
    }
};
