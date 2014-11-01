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
    bool isMirror(TreeNode *l, TreeNode *r)
    {
        if (l == NULL && r == NULL)
            return true;
        else if (l == NULL || r == NULL)
            return false;
        if (l->val != r->val)
            return false;
        if (!isMirror(l->left, r->right) || !isMirror(l->right, r->left))
           return false;
        return true;
        
    }
    bool isSymmetric(TreeNode *root) {
        if (root == NULL)
            return true;
        return isMirror(root->left, root->right);
    }

};
