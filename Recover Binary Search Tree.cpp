class Solution {
public:
    int a = INT_MIN;
    TreeNode *l = NULL, *r = NULL, *p = NULL;
    void recoverTree(TreeNode *root) {
        dfs(root);
        swap(l->val, r->val);
    }
    void dfs(TreeNode *root) {
        if(root == NULL)
            return;
        dfs(root->left);
        if(a > root->val) {
            if(l == NULL)
                l = p;
            r = root;
        }
        a = root->val;
        p = root;
        dfs(root->right);   
    }
};
