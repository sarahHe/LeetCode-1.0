// since it's not perfect trees, you have to finish level by level
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    TreeLinkNode* getFirstNode(TreeLinkNode* node) {
        while (node) {
            if (node->left)
                return node->left;
            else if (node->right)
                return node->right;
            else
                node = node->next;
        }
        return node;
    }

    void connect(TreeLinkNode *root) {
        if (!root || (!root->left && !root->right))  
            return;
        
        TreeLinkNode *parent = root, *node = getFirstNode(root);
        while (parent) {
            if (parent->right && parent->right != node) {
                node->next = parent->right;
                node = node->next;
            }
            
            parent = parent->next;
            node->next = getFirstNode(parent);
            node = node->next;
        }
        connect(getFirstNode(root));
    }
};
