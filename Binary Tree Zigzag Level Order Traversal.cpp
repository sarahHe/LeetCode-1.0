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
        
        deque<TreeNode*>   level;
        level.push_back(root);
        vector<int> value;
        value.push_back(root->val);
        res.push_back(value);
        while (!level.empty()) {
            value.clear();
            deque<TreeNode*> tmp;
            while (!level.empty()) {
                if (res.size() % 2) {
                    if (level.back()->right) {
                        tmp.push_back(level.back()->right);
                        value.push_back(level.back()->right->val);
                    }
                    if (level.back()->left) {
                        tmp.push_back(level.back()->left);
                        value.push_back(level.back()->left->val);
                    }
                    
                }
                else {
                    if (level.back()->left) {
                        tmp.push_back(level.back()->left);
                        value.push_back(level.back()->left->val);
                    }
                    if (level.back()->right) {
                        tmp.push_back(level.back()->right);
                        value.push_back(level.back()->right->val);
                        }
                }
                level.pop_back();
            }
            level = tmp;
            if (!tmp.empty())
                res.push_back(value);
        }
        return res;
    }
};
