// Given a binary tree, determine if it is a valid binary search tree (BST).
// Assume a BST is defined as follows:
// The left subtree of a node contains only nodes with keys less than the node's key.
// The right subtree of a node contains only nodes with keys greater than the node's key.
// Both the left and right subtrees must also be binary search trees.

//corner case: when node is a right child of root. node's left child < node but the it's even < root.
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //be careful about the node value as INT_MIN
class Solution {
public:
    bool check(TreeNode* root, TreeNode* &pre) { //TreeNode* &pre
        if (!root)  return true;
        
        if (!check(root->left, pre))
            return false;
        if (pre != NULL && root->val <= pre->val)    
            return false;
        pre = root;
        return check(root->right, pre);
    }

    bool isValidBST(TreeNode* root) {
        TreeNode *pre = NULL;
        return check(root, pre);
    }
};
