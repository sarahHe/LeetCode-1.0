bool isIdentical(TreeNode *T, TreeNode *S) {
    if (!T && !S)   return true;
    if (!T || !S)   return false;

    return T->val == S->val && 
            isIdentical(T->left, S->left) &&
            isIdentical(T->right, S->right);
}

bool isSubtree(TreeNode *T, TreeNode *S) {
    if (!T) return false;
    if (!S) return true;

    if (isIdentical(T, S))  return true;

    return isSubtree(T->left, S) || isSubtree(T->right, S);
}
