// Two elements of a binary search tree (BST) are swapped by mistake.
// Recover the tree without changing its structure.

// 递归中序遍历二叉树，设置一个pre指针，记录当前节点中序遍历时的前节点，
// 如果当前节点大于pre节点的值，说明需要调整次序。
// 有一个技巧是如果遍历整个序列过程中只出现了一次次序错误，
// 说明就是这两个相邻节点需要被交换。如果出现了两次次序错误，那就需要交换这两个节点。

//this is correct
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
    //copy by reference
    void find(TreeNode *root, TreeNode *&p, TreeNode *&q, TreeNode *&prev) {
        if (!root)  return;
        
        find(root->left, p, q, prev);
        if (prev && root->val > prev->val) {
            if (p == NULL) 
                p = prev;
            q = root;
        }
        prev = root;
        find(root->right, p, q, prev);
    }

    void recoverTree(TreeNode *root) {
        TreeNode *p = NULL, *q=NULL, *prev=NULL;
        find(root, p, q, prev);
        if (p != NULL && q != NULL) 
            swap(p->val, q->val);
    }
};
