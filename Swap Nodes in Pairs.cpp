/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
2015.2.25
ListNode *swapPairs(ListNode *head) {
        if (!head || !head->next)
            return head;
        
        ListNode *newHead = head->next;
        ListNode *newPair = head->next->next;
        head->next->next = head;
        head->next = swapPairs(newPair);
        return newHead;
    }



2015.6.1 update
ListNode* swapPairs(ListNode* head) {
    ListNode *pre = new ListNode(-1);
    pre->next = head;
    ListNode *p = head, *h = pre;
    while (p && p->next) {
        ListNode *q = p->next;
        p->next = q->next;
        q->next = p;
        pre->next = q;
        pre = p;
        p = pre->next;
    }
    return h->next;
}
