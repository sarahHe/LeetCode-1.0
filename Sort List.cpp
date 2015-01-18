/*
Sort a linked list in O(n log n) time using constant space complexity
归并算法！
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
    ListNode *getMid(ListNode *head) {
        ListNode *fast = head,
        *slow = head;
        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    
    ListNode *merge(ListNode *a, ListNode *b) {
        ListNode *dummy_head = new ListNode(-1), *res = dummy_head;
        //这里不能让dummy_head = NULL, res = head;虽然说指针指向的是内容，
        //但似乎初始化为NULL了之后，res也不知道指向哪儿了，并不是指向dummy_head
        while (a && b) {
            if (a->val < b->val) {
                res->next = a;
                a = a->next;
            }
            else {
                res->next = b;
                b = b->next;
            }
            res = res->next;
        }
        res->next = a == NULL ? b : a;
        return dummy_head->next;
    }
    
    ListNode *sortList(ListNode *head) {
        if (!head || !head->next)  return head;
        
        ListNode *mid = getMid(head),
        *mid_next = mid->next;
        mid->next = NULL;
        return merge(sortList(head), sortList(mid_next));
    }
};
