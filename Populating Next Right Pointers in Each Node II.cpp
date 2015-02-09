// since it's not perfect trees, you have to finish level by level
// The solution is not the best best one
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
        if (!root)
            return;
        
        TreeLinkNode *parent = root, *node = getFirstNode(root);
        while (parent && node) {
            while (!parent->left && !parent->right)
                parent = parent->next;
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

// This is the best one
void connect(TreeLinkNode *root) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    if (root == NULL)
        return;
    TreeLinkNode *p = root;
    TreeLinkNode *cntNode = NULL;
    TreeLinkNode *nxtLevel = NULL;
    while (p) {
        if (p->left) {
            if (cntNode)
                cntNode->next = p->left;
            cntNode = p->left;
            if (nxtLevel == NULL)
                nxtLevel = cntNode;
        }
        if (p->right) {
            if (cntNode)
                cntNode->next = p->right;
            cntNode = p->right;
            if (nxtLevel == NULL)
                nxtLevel = cntNode;
        }
        p = p->next;
    }
    connect(nxtLevel);
}
