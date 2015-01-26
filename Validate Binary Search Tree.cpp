// Given a binary tree, determine if it is a valid binary search tree (BST).
// Assume a BST is defined as follows:
// The left subtree of a node contains only nodes with keys less than the node's key.
// The right subtree of a node contains only nodes with keys greater than the node's key.
// Both the left and right subtrees must also be binary search trees.

//corner case: when node is a right child of root. node's left child < node but the it's even < root.
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
    bool check(TreeNode *root, int min, int max) {
        if (!root)  return true;
        

            return root->val > min && root->val < max && check(root->left, min, root->val) && check(root->right, root->val, max);
    }

    bool isValidBST(TreeNode *root) {
        if (!root)  return true;
        
        return check(root->left, INT_MIN, root->val) && check(root->right, root->val, INT_MAX);
    }
};
