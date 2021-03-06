class Solution {
public:
    vector<vector<int> > ans;
    vector<int> v;
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        ans.clear();
        v.clear();
        dfs(root, sum);
        return ans;
    }
    void dfs(TreeNode *root, int sum) {
        if(!root)
            return;
        if(root->left == NULL && root->right == NULL) {
            if(root->val == sum) {
                v.push_back(root->val);
                ans.push_back(v);
                v.pop_back();
            }
            return;
        }
        v.push_back(root->val);
        dfs(root->left, sum - root->val);
        dfs(root->right, sum - root->val);
        v.pop_back();
    }
};


//redo
vector<vector<int>> ans;
vector<int> v;
void dfs(TreeNode* root, int sum) {
  v.push_back(root->val);
  if(root->left == NULL && root->right == NULL) {
    if(sum == root->val) ans.push_back(v);
  }
  if(root->left) dfs(root->left, sum-root->val);
  if(root->right) dfs(root->right, sum-root->val);
  v.pop_back();
}
vector<vector<int>> pathSum(TreeNode* root, int sum) {
  ans.clear(); v.clear();
  if(root)
    dfs(root, sum);
  return ans;
}

