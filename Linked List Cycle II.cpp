/*
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

If meet, has cycle, otherwise no cycle.
after meet, fast and slow advance one step at a time.
When they meet again, they are at the cycle's starting position.

Don't forget defensive programming
*/



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
    ListNode *detectCycle(ListNode *head) {
        if (!head)  return NULL;
        ListNode *fast = head, *slow = head;
        while(fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow)
                break;
        }
        if (!fast->next || !fast->next->next)
            return NULL;
        else {
            slow = head;
            while (slow != fast) {
                fast = fast->next;
                slow = slow->next;
            }
            return slow;
        }
    }
};
