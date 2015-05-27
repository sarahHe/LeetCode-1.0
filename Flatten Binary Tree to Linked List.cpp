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
    void flatten(TreeNode *root) {
        if (root == NULL)
            return;
        
        TreeNode *pLeft = root->left,
                 *pRight = root->right;
        flatten(pLeft);
        flatten(pRight);
        root->left = NULL;
        root->right = pLeft;
        while (root->right != NULL) //To link right subTree to the rightmost of LeftSubtree
            root = root->right;
        root->right = pRight;
    }
};



2015.5.27 update:
 //morris 
 //largest node in the left tree -> child = direct right child
class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode *cur = root;
        while (cur) {
            if (cur->left) {
                TreeNode *pre = cur->left;
                while (pre->right)
                    pre = pre->right;
                pre->right = cur->right;
                cur->right = cur->left;
                cur->left = NULL;
            }
            cur = cur->right;
        }
    }
};
