2015.6.1 update
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head)  return head;
        ListNode *p = head, *q = head, *t = head;
        int size = 0;
        while (t) {
            t = t->next;
            size++;
        }
        k %= size;
        
        for (int i = 0; i < k && q; i++) 
            q = q->next;
        while (q && q->next) {
            p = p->next;
            q = q->next;
        }
        q->next = head;
        head = p->next;
        p->next = NULL;
        return head;
    }
};


2015.3.1 update
// 首先从head开始跑，直到最后一个节点，这时可以得出链表长度len。然后将尾指针指向头指针，将整个圈连起来，接着往前跑len – k%len，从这里断开，就是要求的结果了
// 注意K大于len的可能。
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
    ListNode *rotateRight(ListNode *head, int k) {
        if (!head || k == 0)
            return head;
            
        int len = 1;
        ListNode *p = head;
        while (p->next) {
            len++;
            p = p->next;
        }
        p->next = head;
        
        k = len - k %len;// 注意K大于len的可能。
        int i = 0;
        while (i < k) {
            p = p->next;
            i++;
        }
        head = p->next;
        p->next = NULL;
        return head;
    }
};
