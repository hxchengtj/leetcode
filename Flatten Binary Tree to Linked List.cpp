class Solution {
public:
    TreeNode *l = NULL;
    void flatten(TreeNode *root) {
        if(root == NULL)
            return;
        TreeNode *a, *b;
        a = root->left;
        b = root->right;
        if(l) 
            l->right = root;
        l = root;
        l->left = NULL;
        flatten(a);
        flatten(b);
    }
    
};
