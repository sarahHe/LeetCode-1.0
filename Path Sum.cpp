//Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.
// there might be negative numbers
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
    bool found(TreeNode *root, int res, int sum) {
        if (!root->left && !root->right)
            return res + root->val == sum;
            
        if (root->left && found(root->left, res + root->val, sum))
            return true;
        if (root->right && found(root->right, res + root->val, sum))
            return true;
        return false;
    }

    bool hasPathSum(TreeNode *root, int sum) {
        if (root == NULL)   return false;
        return found(root, 0, sum);
    }
};
