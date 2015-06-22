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
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void inOrderTraversal(TreeNode* root) {
        if (!root)  return;
        inOrderTraversal(root->left);
        if (pre->val > root->val) {
            if (f1 == NULL)
                f1 = pre;
            f2 = root; //no else for the neighboring nodes
        }
        pre = root;//!!
        inOrderTraversal(root->right);
    }

    void recoverTree(TreeNode* root) {
        inOrderTraversal(root);
        if (f1 && f2)
            swap(f1->val, f2->val);//swap value
    }
private:
    TreeNode *pre = new TreeNode(INT_MIN), *f1 = NULL, *f2 = NULL;
    //must use private members, can't just use parameters. The value gets overrided in each stack
};
