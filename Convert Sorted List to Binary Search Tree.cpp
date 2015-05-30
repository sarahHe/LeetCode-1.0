/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *makeBST(ListNode *ptr, int low, int high) {
        if (low > high) return NULL;
        
        int mid = low + (high - low) / 2;
        ListNode *p = ptr;
        for (int i = low; i < mid; i++)
            p = p->next;
        TreeNode *root = new TreeNode(p->val);
        root->left = makeBST(ptr, low, mid - 1);
        root->right = makeBST(p->next, mid + 1, high);
        return root;
    }

    TreeNode *sortedListToBST(ListNode *head) {
        if (!head)  return NULL;
        
        ListNode *p = head;
        int len = 0;
        while (p) {
            len++;
            p = p->next;
        }
        
        return makeBST(head, 0, len - 1);
    }
};



class Solution {
public:
    TreeNode* build(ListNode* head, ListNode* tail) {
        if (head == tail)   return NULL;
        if (head->next == tail) return new TreeNode(head->val);
        
        ListNode *slow = head, *fast = head;
        while (fast != tail && fast->next != tail) {//!= tail rather than != NULL
            slow = slow->next;
            fast = fast->next->next;
        }
        TreeNode* node = new TreeNode(slow->val);
        node->left = build(head, slow);
        node->right = build(slow->next, tail);//slow->next
        return node;
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        return build(head, NULL); // tail is NULL
    }
};
