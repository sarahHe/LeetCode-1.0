/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root || !root->left)  return;
        
        root->left->next = root->right;
        if (root->next)
            root->right->next = root->next->left;
        connect(root->left);
        connect(root->right);
    }
};



2015.5.5 update
 //iteration method level by level
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root)  return;
        TreeLinkNode *pre = root, *cur = NULL;
        while (pre->left) {
            cur = pre;
            while(cur) {
                cur->left->next = cur->right;
                if (cur->next)
                    cur->right->next = cur->next->left;
                cur = cur->next;
            }
            pre = pre->left; //next level
        }
    }
};
