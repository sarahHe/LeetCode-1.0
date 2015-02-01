// Merge k sorted linked lists and return it as one sorted list. 
// Analyze and describe its complexity.

//use priority queue to do the sort
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct cmp {
    bool operator()(ListNode* n1, ListNode* n2) {
        return n1->val > n2->val;
    }
}; 
 
class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if (lists.empty())  return NULL;
        
        ListNode *res = new ListNode(-1), *cur = res;
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
        for (int i = 0; i < (int)lists.size(); i++) {
            if (lists[i])
                pq.push(lists[i]);
        }
        while (!pq.empty()) {
            ListNode *tmp = pq.top();
            cur->next = tmp;
            cur = cur->next;
            if (tmp->next)
                pq.push(tmp->next);
            pq.pop();
        }
        return res->next;
    }
};
