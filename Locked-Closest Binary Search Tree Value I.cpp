//recursive
class Solution {
public:
  int closestValue(TreeNode* root, double target) {
    if(root->val == target) return target;
    TreeNode* t = root->val < target? root->right:root->left;
    if(!t) return root->val;
    int a = closestValue(t, target), b = root->val;
    return abs(a-target) < abs(b-target) ? a:b;
  }
};

//iterative
class Solution {
public:
  int closestValue(TreeNode* root, double target) {
    int ans = root->val;
    while(root) {
      if(abs(ans-target) > abs(root->val-target)) ans = root->val;
      root = root->val < target? root->right: root->left;
    }
    return ans;
  }
};
