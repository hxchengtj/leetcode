class Solution {
public:
    TreeNode *sortedArrayToBST(vector<int> &num) {
        return dfs(num, 0, num.size()-1);
    }
    TreeNode *dfs(vector<int> &num, int l, int r) {
        if(l > r)
            return NULL;
        int m = (l+r)/2;
        TreeNode *t = new TreeNode(num[m]);
        t->left = dfs(num, l, m-1);
        t->right = dfs(num, m+1, r);

    }
};

//redo
TreeNode* dfs(vector<int>& nums, int l, int r) {
  if(l >= r) return NULL;
  int m = l + (r-l)/2;
  TreeNode* t = new TreeNode(nums[m]);
  t->left = dfs(nums, l, m);
  t->right = dfs(nums, m+1, r);
  return t;
}
TreeNode* sortedArrayToBST(vector<int>& nums) {
  return dfs(nums, 0, nums.size());
}

