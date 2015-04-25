//Sort a linked list using insertion sort.

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
    ListNode* insertionSortList(ListNode* head) {
        ListNode helper(-1), *pre, *current = head; 
        // helper.next = head; infinite loop with this line
        while (current) {
            pre = &helper;
            while (pre->next && pre->next->val < current->val)
                pre = pre->next;
            ListNode *next = current->next;
            current->next = pre->next;
            pre->next = current;
            current = next;
        }
        return helper.next;
    }
};
