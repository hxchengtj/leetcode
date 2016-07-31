//redo
class Solution {
public:
  int largestBSTSubtree(TreeNode* root) {
    if(!root) return 0;
    int ans = 0, minv = root->val, maxv = root->val;
    dfs(root, minv, maxv, ans);           //此处调用不能直接写root->val, 0, 因为是传引用
    return ans;
  }
  bool dfs(TreeNode* root, int &minv, int &maxv, int& ans) {
    bool isBst = true;
    minv = maxv = root->val;
    int minl = INT_MIN, maxl = INT_MAX, cntl = 0;
    if(root->left) {
      if(dfs(root->left, minl, maxl, cntl)) {
        minv = min(minl, minv);
        if(maxl >= root->val) isBst = false; 
      } else isBst = false;
    }
    int minr = INT_MIN, maxr = INT_MAX, cntr = 0;
    if(root->right) {
      if(dfs(root->right, minr, maxr, cntr)) {        
        maxv = max(maxr, maxv);
        if(minr <= root->val) isBst = false; 
      } else isBst = false;
    }
    if(isBst) 
      ans = cntl+cntr+1;
    else ans = max(cntl, cntr);
    return isBst;
  }
};
