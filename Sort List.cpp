/*
Sort a linked list in O(n log n) time using constant space complexity
归并算法！
*/

2015.4.24 update run time from 86ms to 62ms
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
    ListNode *merge(ListNode *head1, ListNode *head2) {
        ListNode dummy(-1), *res = &dummy;
        while (head1 && head2) {
            if (head1->val < head2->val) {
                res->next = head1;
                head1 = head1->next;
            }
            else {
                res->next = head2;
                head2 = head2->next;
            }
            res = res->next;
        }
        
        res->next = (head1 == NULL) ? head2 : head1;
        return dummy.next;
    }

    ListNode *getMid(ListNode *head) {
        if (head == NULL || head->next == NULL) return head;
        
        ListNode *fast = head->next->next, *slow = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode *sortList(ListNode *head) {
        if (head == NULL || head->next == NULL) return head;
        
        ListNode *midNode = getMid(head);
        ListNode *secHead = midNode->next;
        midNode->next = NULL;// important
        return merge(sortList(head), sortList(secHead));
    }
};
