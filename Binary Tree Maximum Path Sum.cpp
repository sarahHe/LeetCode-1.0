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
    int getSum(TreeNode *root, int &global) {
        if (root == NULL)   return 0;
        
        int left = getSum(root->left, global);
        int right = getSum(root->right, global);
        int sum = root->val;
        if (left > 0)
            sum += left;
        if (right > 0)
            sum += right;
        global = max(sum, global);
        
        return (max(left, right) > 0) ? max(left, right) + root->val : root->val;
    }

    int maxPathSum(TreeNode *root) {
        int global = INT_MIN;
         getSum(root, global);
         return global;
    }
};


2015.4.30 update
//more clear
class Solution {
public:
    int findPath(TreeNode *root, int &res) {
        if (!root)  return 0;
        int left = findPath(root->left, res),
            right = findPath(root->right, res);
        res = max(res, left + right + root->val);
        return max(0, max(left, right) + root->val);
    }

    int maxPathSum(TreeNode *root) {
        if (!root)  return 0;
        int res = root->val;
        findPath(root, res);
        return res;
    }
};
