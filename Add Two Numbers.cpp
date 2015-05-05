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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        int carry = 0;
        ListNode *dummy = new ListNode(-1), *res = dummy;
        while (l1 && l2) {
            ListNode *node = new ListNode((l1->val + l2->val + carry ) % 10);
            carry = (l1->val + l2->val + carry ) / 10;
            dummy->next = node;
            dummy = dummy->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1) {
            ListNode *node = new ListNode((l1->val + carry ) % 10);
            carry = (l1->val + carry ) / 10;
            dummy->next = node;
            dummy = dummy->next;
            l1 = l1->next;
        }
        while (l2) {
            ListNode *node = new ListNode((l2->val + carry ) % 10);
            carry = (l2->val + carry ) / 10;
            dummy->next = node;
            dummy = dummy->next;
            l2 = l2->next;
        }
        if (carry) {
            ListNode *node = new ListNode(carry);
            dummy->next = node;
        }
        return res->next;
    }
};



2015.5.5 update
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(-1), *cur = &dummy;
        int sum = 0;
        while (l1 || l2) {
            sum /= 10;
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }
            ListNode *node = new ListNode(sum % 10);
            cur->next = node;
            cur = cur->next;
        }
        if (sum / 10)
            cur->next = new ListNode(sum/10);
        return dummy.next;
        
    }
};
