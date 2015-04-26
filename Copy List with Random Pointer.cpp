/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (!head)  return NULL;
        
        RandomListNode *p = head, *q = new RandomListNode(head->label);
        unordered_map<RandomListNode*, RandomListNode*> mp;
        mp[head] = q;
        while (p) {
            if (p->next) {
                if (mp[p->next])
                    q->next = mp[p->next];//!!
                else {
                    q->next = new RandomListNode(p->next->label);
                    mp[p->next] = q->next;
                }
            }
            if (p->random) {
                if (mp[p->random])
                    q->random = mp[p->random];
                else {
                    q->random = new RandomListNode(p->random->label);
                    mp[p->random] = q->random;
                }
            }
            p = p->next;
            q = q->next;
        }
        return mp[head];//!!!
    }
};


// another solution O(N) time complexity O(1) space
// The algorithm is composed of the follow three steps which are also 3 iteration rounds.

// Iterate the original list and duplicate each node. The duplicate of each node follows its original immediately.
// Iterate the new list and assign the random pointer for each duplicated node.
// Restore the original list and extract the duplicated nodes.
public RandomListNode copyRandomList(RandomListNode head) {
    RandomListNode iter = head, next;

    // First round: make copy of each node,
    // and link them together side-by-side in a single list.
    while (iter != null) {
        next = iter.next;

        RandomListNode copy = new RandomListNode(iter.label);
        iter.next = copy;
        copy.next = next;

        iter = next;
    }

    // Second round: assign random pointers for the copy nodes.
    iter = head;
    while (iter != null) {
        if (iter.random != null) {
            iter.next.random = iter.random.next;
        }
        iter = iter.next.next;
    }

    // Third round: restore the original list, and extract the copy list.
    iter = head;
    RandomListNode pseudoHead = new RandomListNode(0);
    RandomListNode copy, copyIter = pseudoHead;

    while (iter != null) {
        next = iter.next.next;

        // extract the copy
        copy = iter.next;
        copyIter.next = copy;
        copyIter = copy;

        // restore the original list
        iter.next = next;

        iter = next;
    }

    return pseudoHead.next;
}
