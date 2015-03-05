// Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).
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
        vector<vector<int> >    res;
        if (!root)  return res;   
        
        vector<TreeNode*> next_level_node;
        next_level_node.push_back(root);
        bool odd = false;
        while (!next_level_node.empty()) {
            vector<TreeNode*> tmp;
            vector<int> next_level_value;
            for (int i = next_level_node.size() - 1, j = 0; i >= 0, j < next_level_node.size(); i--, j++) {
                next_level_value.push_back(next_level_node[j]->val); //value is always from left to right
                if (odd) { // node will be stored in the correct order
                    if (next_level_node[i]->left) //when read from previos line, always start from right
                        tmp.push_back(next_level_node[i]->left);
                    if (next_level_node[i]->right)
                        tmp.push_back(next_level_node[i]->right);
                }
                else {
                    if (next_level_node[i]->right)
                        tmp.push_back(next_level_node[i]->right);
                    if (next_level_node[i]->left)
                        tmp.push_back(next_level_node[i]->left);
                }
            }
            odd = !odd;
            res.push_back(next_level_value);
            next_level_node = tmp;
        }
        return res;
    }
};
