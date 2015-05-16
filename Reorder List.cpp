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


2015.5.16 update
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
    void reorderList(ListNode* head) {
        if (head == NULL || head->next == NULL)   return;
        
        //find mid
        ListNode *fast = head, *slow = head;
        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode *head2 = slow->next;
        slow->next = NULL; //not slow = NULL;
        
        //reverse
        ListNode *p = head2;
        while(p->next) { //not while(p), and p is always the first node before reverse, so p won't change
            ListNode *q = p->next;
            p->next = q->next;
            q->next = head2; // not q->next = p
            head2 = q;
        }
        
        //merge
        ListNode *cur = new ListNode(-1);
        while (head || head2) {
            if (head) {
                cur->next = head;
                head = head->next;
                cur = cur->next;
            }
            if (head2) {
                cur->next = head2;
                head2 = head2->next;
                cur = cur->next;
            }
        }
    }
};
