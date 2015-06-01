/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
2015.5.31 update
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *pre = new ListNode(-1), *q = pre;
        pre->next = head;
        int pos = 1;
        while (pos != m) {
            pre = pre->next;
            head = head->next;
            pos++;
        }
        
        while (pos != n && head) {
            ListNode *t = head->next;
            head->next = t->next;
            t->next = pre->next;
            pre->next = t;
            pos++;
        }
        return q->next;
    }
};
