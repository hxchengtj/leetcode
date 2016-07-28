class Solution {
public:
  vector<vector<int>> findLeaves(TreeNode* root) {
    vector<vector<int>> ans;
    dfs(ans, root);
    return ans;
  }
  int dfs(vector<vector<int>> &ans, TreeNode* root) {
    if(root == NULL) return -1;
    int h = max(dfs(ans, root->left), dfs(ans, root->right)) + 1;
    if(ans.size() < h+1) ans.push_back({root->val});
    else ans[h].push_back(root->val);
    return h;
  }
};
