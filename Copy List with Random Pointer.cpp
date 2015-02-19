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
