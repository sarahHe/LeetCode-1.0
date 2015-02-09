// Given a binary tree, return the bottom-up level order traversal of its 
// nodes' values. (ie, from left to right, level by level from leaf to root).

// just use rbegin() and rend()
//another way: use stack
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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int> > res;
        if (!root)
            return res;
        
        vector<TreeNode*> level;
        level.push_back(root);
        while (!level.empty()) {
            vector<TreeNode*> tmp;
            vector<int> level_res;
            for (auto i : level) {
                level_res.push_back(i->val);
                if (i->left)
                    tmp.push_back(i->left);
                if (i->right)
                    tmp.push_back(i->right);
            }
            level.clear();
            level = tmp;
            res.push_back(level_res);
        }
        return vector<vector<int> > (res.rbegin(), res.rend());
    }
};
