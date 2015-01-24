//Given a linked list and a value x, partition it such that all nodes less than x 
//come before nodes greater than or equal to x.
//You should preserve the original relative order of the nodes in each of the two partitions.
//For example,
//Given 1->4->3->2->5->2 and x = 3,
//return 1->2->2->4->3->5. 

//using two pointer, one marks the less_than aother marks the greater_than
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
    ListNode *partition(ListNode *head, int x) {
        if (!head)  return head;
        ListNode less(-1), gtr(-1), 
                *t = head, 
                *ls_cur = &less, *gt_cur = &gtr;
        while (t) {
            if (t->val < x) {
                ls_cur->next = t;
                ls_cur = ls_cur->next;
            }
            else {
                gt_cur->next = t;
                gt_cur = gt_cur->next;
            }
            t = t->next;
        }
        ls_cur->next = NULL; //The two lines are important. Without them,
        gt_cur->next = NULL; //the program goes into infinite loop.
        if (!less.next)    return gtr.next;
        ls_cur->next = gtr.next;
        return less.next;
    }
};
