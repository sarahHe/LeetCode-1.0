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

2015.4.19 update
// Two pointer solution (O(n+m) running time, O(1) memory):
// Maintain two pointers pA and pB initialized at the head of A and B, respectively. Then let them both traverse through the lists, one node at a time.
// When pA reaches the end of a list, then redirect it to the head of B (yes, B, that's right.); similarly when pB reaches the end of a list, redirect it the head of A.
// If at any point pA meets pB, then pA/pB is the intersection node.
// To see why the above trick would work, consider the following two lists: A = {1,3,5,7,9,11} and B = {2,4,9,11}, which are intersected at node '9'. Since B.length (=4) < A.length (=6), pB would reach the end of the merged list first, because pB traverses exactly 2 nodes less than pA does. By redirecting pB to head A, and pA to head B, we now ask pB to travel exactly 2 more nodes than pA would. So in the second iteration, they are guaranteed to reach the intersection node at the same time.
// If two lists have intersection, then their last nodes must be the same one. So when pA/pB reaches the end of a list, record the last element of A/B respectively. If the two last elements are not the same one, then the two lists have no intersections.
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
        if (headA == NULL || headB == NULL) return NULL;
        
        ListNode *pa = headA, *pb = headB;
        while (pa != pb) {
            // if pa == NULL or Pb == NULL, no intersection
            pa = pa->next;
            pb = pb->next;
            
            if (pa == pb)   return pa;
            if (pa == NULL) pa = headB;
            if (pb == NULL) pb = headA;
        }
        return pa;
    }
};
