// 1. find the mid point of the list
// 2. reverse the second half of linked list
// 3. check the two half
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
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next)   return true;
        
        ListNode *slow = head, *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        // reverse the second half
        // slow->next is the head of second half
        ListNode *h = slow->next, *q = h->next;
        while (q) {
            ListNode *t = slow->next;
            slow->next = q;
            h->next= q->next;
            q->next = t;
            q = h->next;
        }
        
        // check if the two half the same
        h = slow->next;
        while (h) {
            if (head->val != h->val)
                return false;
            head = head->next;
            h = h->next;
        }
        return true;
    }
};
