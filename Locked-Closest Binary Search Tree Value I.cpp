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
