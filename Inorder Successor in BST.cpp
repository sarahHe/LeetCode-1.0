TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
    if (p->right) {
        TreeNode *node = p->right;
        while (node->left)
            node = node->left;
        return node;
    }
    
    TreeNode *succesor = nullptr;
    while (root) {
        if (p->val < root->val) {
            succesor = root;
            root = root->left;
        }
        else if (p->val > root->val)
            root = root->right;
        else
            break;
    }
    return succesor;
}
