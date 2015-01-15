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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> > res;
        if (root == NULL)   return  res;
        
        vector<TreeNode*>   level;
        level.push_back(root);
        int k = 1;
        while (!level.empty()) {
            res.push_back(level);///////////
            if (level.size() % 2 == 1) {
                vector<int> value;
                for (int i = res.back().size() - 1; i >= 0; i--) {
                    value.push_back(level[i]->right->val);
                    value.push_back(level[i]->left->val);
                    
                }
            }
            else {
                for (int i = 0; i < res.back().size(); i++) {
                    level.push_back(res.back()[i]);
                }
            }
                
        }
        return res;
    }
};
