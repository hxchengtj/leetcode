//redo
class Solution {
public:
  int countUnivalSubtrees(TreeNode* root) {
    int count = 0;
    dfs(root, count, 0);
    return count;
  }
  bool dfs(TreeNode* root, int & count, int val) {
    if(root == NULL) return true;
    if(!dfs(root->left, count, root->val) | !dfs(root->right, count, root->val))
      return false;
    count++;
    return root->val == val;
  }
};
