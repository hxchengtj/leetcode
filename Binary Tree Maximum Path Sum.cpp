 // review
class Solution {
public:
    int maxPathSum(TreeNode *root) {
        pair<int ,int> p;           //<最大路径，到达此点的最大路径>
        p = dfs(root);
        return p.first;
    }
    pair<int, int> dfs(TreeNode *root) {
        if(root == NULL)
            return make_pair(INT_MIN, 0);
        pair<int, int> l, r, ans;
        l = dfs(root->left);
        r = dfs(root->right);
        ans.second = max({root->val, l.second+root->val, r.second+root->val});
        ans.first = max({l.first, r.first, ans.second, root->val+l.second+r.second});
        return ans;
    }
};

//redo
pair<int, int> __maxPathSum(TreeNode* root) {
  int ans = root->val, lsingle = root->val, rsingle = root->val;
  if(root->left) {
    pair<int, int> lp = __maxPathSum(root->left);
    ans = max(lp.first, ans);
    lsingle = max(lp.second+root->val, lsingle);
  }
  if(root->right) {
    pair<int, int> rp = __maxPathSum(root->right);
    ans = max(rp.first, ans);
    rsingle = max(rp.second+root->val, rsingle);
  }
  return make_pair(max(ans, lsingle+rsingle-root->val), max(lsingle, rsingle));

}
int maxPathSum(TreeNode* root) {
  if(root == NULL) return 0;
  return __maxPathSum(root).first;
}


