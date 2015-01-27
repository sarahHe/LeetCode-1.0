// Merge two sorted linked lists and return it as a new list. 
// The new list should be made by splicing together the nodes of the first two lists.
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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *dummy = new ListNode(-1), *res = dummy;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                res->next = l1;
                l1 = l1->next;
            }
            else {
                res->next = l2;
                l2 = l2->next;
            }
            res = res->next;
        }
        if (l1)
            res->next = l1;
        if (l2)
            res->next = l2;
        return dummy->next;
    }
};
