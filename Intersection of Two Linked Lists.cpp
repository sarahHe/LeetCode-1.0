// Write a program to find the node at which 
// the intersection of two singly linked lists begins.

//Solution 1: traverse both A and B get the length 
// visit the longer one first until the rest of the list is 
//at the same length of the other one
//Solution 2: traverse A and B; Traverse B and A.
// If at any point pA meets pB, then pA/pB is the intersection node. 
// Otherwise return NULL
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB)   return NULL;
        
        ListNode *p1 = headA, *p2 = headB;
        int len1 = 0, len2 = 0;
        while (p1) {
            len1++;
            p1 = p1->next;
        }
        while (p2) {
            len2++;
            p2 = p2->next;
        }
        p1 = headA, p2 = headB;
        while (len1 > len2) {
            p1 = p1->next;
            len1--;
        }
        while (len2 > len1) {
            p2 = p2->next;
            len2--;
        }
        while (p1 != p2 && p1 && p2) {
            p1 = p1->next;
            p2 = p2->next;
        }
        if (p1 == p2)
            return p1;
        else
            return NULL;
    }
};
