int longestHelper(TreeNode *node, int parentVal, int len) {
	if (!node)	return	len;

	len = parentVal + 1 == node->val ? len + 1 : 1;
	int left = longestHelper(node->left, node->val, len);
	int right = longestHelper(node->right, node->val, len);
	return max(len, max(left, right));
}

int longestConsecutive(TreeNode *root) {
	return longestHelper(root, root->val, 0);
}
