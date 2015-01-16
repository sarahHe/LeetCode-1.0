//Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

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
    void helper(TreeNode *root, vector<int> path, vector<vector<int>> &res, int total, int sum) {
        if (!root)  return; // you can't early terminate the program by judging if total > sum, return. Because the value of the node could be negative. The total would be smaller and smaller then.
        
        if (!root->left && !root->right && total + root->val == sum) {
            path.push_back(root->val);
            res.push_back(path);
            return; 
        }
        path.push_back(root->val);
        total += root->val;
        helper(root->left, path, res, total, sum);
        helper(root->right, path, res, total, sum);
    }

    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int>> res;
        vector<int> path;
        helper(root, path, res, 0, sum);
        return res;
    }
};
