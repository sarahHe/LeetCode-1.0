// Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.
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
    void view(TreeNode *root, vector<int> &res, int depth) {
        if (root == NULL)   return;
        
        if (depth == res.size())
            res.push_back(root->val);
        view(root->right, res, depth+1);
        view(root->left, res, depth+1);
    }
    
    vector<int> rightSideView(TreeNode *root) {
        vector<int> res;
        if (root == NULL)   return res;
        
        view(root, res, 0);
        return res;
    }
    // the following solution can not get those unique node in the row
    // void view(TreeNode *root, vector<int> &res) {
    //     if (root == NULL)   return;
        
    //     res.push_back(root->val);
    //     if (root->right) {
    //         view(root->right, res);
    //     }
    //     else if (root->left){
    //         view(root->left, res);
    //     }
    // }
    
    // vector<int> rightSideView(TreeNode *root) {
    //     vector<int> res;
    //     view(root, res);
    //     return res;
    // }
};





2015.5.23 update
class Solution {
public:
    void nextLevel(TreeNode* root, int level, vector<int> &res) {
        if (!root)  return;
        
        if (res.size() < level) res.push_back(root->val);
        nextLevel(root->right, level+1, res);
        nextLevel(root->left, level+1, res);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        nextLevel(root, 1, res); //1 instead of 0
        return res;
    }
};
