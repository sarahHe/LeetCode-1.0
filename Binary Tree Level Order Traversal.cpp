//Given a binary tree, return the level order traversal 
//of its nodes' values. (ie, from left to right, level by level).
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
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> >    res;
        if (!root)  return res;
        
        vector<TreeNode*> level;
        level.push_back(root);
        while (!level.empty()) {
            vector<int> tmp;
            vector<TreeNode*> next;
            for (int i=0; i<level.size();i++) {
                if(level[i]->left)
                    next.push_back(level[i]->left);
                if (level[i]->right)
                    next.push_back(level[i]->right);
                tmp.push_back(level[i]->val);
            }
            res.push_back(tmp);
            level = next;
        }
        return res;
    }
};
