class Solution {
public:
  int longestConsecutive(TreeNode* root) {
    return dfs(root, NULL, 0);
  }
  int dfs(TreeNode* root, TreeNode* parent, int cnt) {
    if(!root) return 0;
    if(parent && parent->val == root->val-1) cnt++;
    else cnt = 1;
    return max({cnt, dfs(root->left, root, cnt), dfs(root->right, root, cnt)});
  }

};

