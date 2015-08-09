/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        if(root == NULL)
            return false;
        if(root->left == NULL && root->right == NULL)
        {
            if(sum == root->val)
                return true;
            else
                return false;
        }
        sum -= root->val;
        return hasPathSum(root->left, sum) || hasPathSum(root->right, sum);
    }
};

//redo
bool hasPathSum(TreeNode* root, int sum) {
  if(root == NULL) return false;
  if(root->left == NULL && root->right == NULL && root->val == sum)
    return true;
  return hasPathSum(root->left, sum-root->val) || hasPathSum(root->right, sum-root->val);
}

