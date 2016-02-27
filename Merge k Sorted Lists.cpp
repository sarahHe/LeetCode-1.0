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



2016.2.27 resursive method
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty())  return NULL;
        
        while (lists.size() > 1) {
            lists.push_back(mergeTwoLists(lists[0], lists[1]));
            lists.erase(lists.begin());
            lists.erase(lists.begin());
        }
        return lists.front();
    }
    
    ListNode* mergeTwoLists(ListNode *l1, ListNode *l2) {
        if (!l1)    return l2;
        if (!l2)    return l1;
        
        if (l1->val <= l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }  
    }
};
