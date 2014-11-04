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
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> ans, v;
        if(root == NULL)
            return ans;
        ans = inorderTraversal(root->left);
        ans.push_back(root->val);
        v = inorderTraversal(root->right);
        ans.insert(ans.end(), v.begin(), v.end());
        return ans;
    }
};
