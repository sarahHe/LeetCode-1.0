// Given a binary tree, return all root-to-leaf paths.

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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if (!root)  return res;
        helper(root, res, "");
        return res;
    }
    
    void helper(TreeNode *root, vector<string> &res, string tmp) {
        if (!root->left && !root->right) // The leaf nodes only append val
            res.push_back(tmp + to_string(root->val));

        // The other nodes append val->
        if (root->left)
            helper(root->left, res, tmp + to_string(root->val) + "->"); 
        if (root->right)
            helper(root->right, res, tmp + to_string(root->val) + "->");
        
    }
};
