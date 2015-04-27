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
    int getNum(TreeNode *root, int num) {
        if (!root->left && !root->right)
            return 10*num + root->val;
        if (!root->left && root->right)
            return getNum(root->right, 10*num + root->val);
        else if (root->left && !root->right)
            return getNum(root->left, 10*num + root->val);
        
        return getNum(root->left, 10*num + root->val) + getNum(root->right, 10*num + root->val);
    }

    int sumNumbers(TreeNode *root) {
        if (!root)  return 0;
        
        int num = 0, total=0;
        return getNum(root, total);
    }
};


2015.4.26 update reduce time from 9ms to 5ms
class Solution {
public:
    int getSum(TreeNode *root, int res) {
        if (!root)  return 0; //return 0 rather than res
        
        if (!root->left && !root->right)    return res*10+root->val;
        return getSum(root->left, res*10 + root->val) + getSum(root->right, res*10+root->val);
    }
    
    int sumNumbers(TreeNode *root) {
        return getSum(root, 0);
    }
};
