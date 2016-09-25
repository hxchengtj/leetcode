/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        return dfs(root, false);
    }
    int dfs(TreeNode* root, bool flag) {
        if(!root) return 0;
        if(!root->left && !root->right) {
            if(flag) return root->val;
            return 0;
        }
        return dfs(root->left, true) + dfs(root->right, false);
    }
};
