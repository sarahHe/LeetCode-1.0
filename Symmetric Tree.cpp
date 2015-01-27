// Given a binary tree, check whether it is a mirror of itself
// (ie, symmetric around its center).

//remember it's symmetric based on the center
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
    bool helper(TreeNode *left, TreeNode *right) {
        if (!left && !right)    return true;
        
        if (left && right && left->val == right->val)
            return helper(left->left, right->right) && helper(left->right, right->left);
        else
            return false;
    }

    bool isSymmetric(TreeNode *root) {
        if (!root)  return true;
        return helper(root->left, root->right);
    }
};
