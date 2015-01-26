// Given a singly linked list L: L0→L1→…→Ln-1→Ln,
// reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
// You must do this in-place without altering the nodes' values.

//用deque 一前一后的重新接入
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
    void reorderList(ListNode *head) {
        if (!head || !head->next)  return;
        
        deque<ListNode*> dq;
        ListNode *p = head;
        while (p) {
            dq.push_back(p);
            p = p->next;
        }
        
        ListNode *cur = head;
        while (!dq.empty()) {
            cur->next = dq.front();
            cur = cur->next;
            dq.pop_front();
            if (!dq.empty()) {
                cur->next = dq.back();
                cur = cur->next;
                dq.pop_back();
            }
        }
        cur->next = NULL;
    }
};
