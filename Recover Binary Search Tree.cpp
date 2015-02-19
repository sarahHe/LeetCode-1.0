// Two elements of a binary search tree (BST) are swapped by mistake.
// Recover the tree without changing its structure.

// 递归中序遍历二叉树，设置一个pre指针，记录当前节点中序遍历时的前节点，
// 如果当前节点大于pre节点的值，说明需要调整次序。
// 有一个技巧是如果遍历整个序列过程中只出现了一次次序错误，
// 说明就是这两个相邻节点需要被交换。如果出现了两次次序错误，那就需要交换这两个节点。

// Two elements of a binary search tree (BST) are swapped by mistake.
// Recover the tree without changing its structure.

// 递归中序遍历二叉树，设置一个pre指针，记录当前节点中序遍历时的前节点，
// 如果当前节点大于pre节点的值，说明需要调整次序。
// 有一个技巧是如果遍历整个序列过程中只出现了一次次序错误，
// 说明就是这两个相邻节点需要被交换。如果出现了两次次序错误，那就需要交换这两个节点。
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
    void recoverTree(TreeNode *root) {
        if (!root)  return;
        
        TreeNode *f1 = NULL, *f2 = NULL,
            *pre, *cur = root, *parent = NULL;
        while (cur) {
            if (cur->left == NULL) {
                if (parent && parent->val > cur->val) {
                    if (f1 == NULL)
                        f1 = parent;
                    f2 = cur;
                }
                parent = cur;
                cur = cur->right;
            }
            else { 
                pre = cur->left;
                while (pre->right && pre->right != cur)
                    pre = pre->right;
                    
                if (pre->right == NULL) {
                    pre->right = cur;
                    cur = cur->left;
                }
                else {
                    pre->right = NULL;
                    if (parent->val > cur->val) {
                        if (f1 == NULL)
                            f1 = parent;
                        f2 = cur;
                    }
                    parent = cur;
                    cur = cur->right;
                }
            }
        }
        if (f1 && f2)
            swap(f1->val, f2->val);
    }
};

