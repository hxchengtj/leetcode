/* review again */
int sumNumbers(TreeNode* root) {
  if(root == NULL) return 0;
  return __sumNumbers(root, 0);
}

int __sumNumbers(TreeNode* root, int a) {
  a = a*10+root->val;
  if(root->left == NULL && root->right == NULL) return a;
  int ans = 0;
  if(root->left) ans += __sumNumbers(root->left, a);
  if(root->right) ans += __sumNumbers(root->right, a);
  return ans;
}


