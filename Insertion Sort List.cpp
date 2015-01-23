//Sort a linked list using insertion sort.

//just be careful about the every scenarios.
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
    ListNode *insertionSortList(ListNode *head) {
        if (!head)  return NULL;
        
        ListNode *p = head, *q = head->next;
        while (q) {
            if (q->val >= p->val) {
                p = q;
                q = q->next;
            }
            else {
                ListNode *t = head, *t_pre = head;
                while (t != q) {
                    if (q->val >= t->val) {
                        t_pre = t;
                        t = t->next;
                    }
                    else {
                        p->next = q->next;
                        q->next = t;
                        if (t != head) 
                            t_pre->next = q;
                        else 
                            head = q;
                        q = p->next;
                        break;
                    }
                }
            }
        }
        return head;
    }
};

other's solution:
class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        ListNode *ret = NULL, *tmp = head, *nxt = NULL;
        ListNode **pCur = &ret;
        while (tmp) {
            pCur = &ret;
            while (*pCur && (*pCur)->val <= tmp->val)
                pCur = &((*pCur)->next);
            nxt = tmp->next;
            tmp->next = *pCur;
            *pCur = tmp;
            tmp = nxt;
        }
        return ret;
    }
};
