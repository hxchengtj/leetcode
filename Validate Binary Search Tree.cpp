class Solution {
public:
    int v;
    bool isValidBST(TreeNode *root) {
        if(root == NULL)
            return 1;
        v = -1000000000;
        return ldr(root);
    }
    bool ldr(TreeNode *root) {
        if(root == NULL)
            return 1;
        if(!ldr(root->left))
            return 0;
        if(v >= root->val)
            return 0;
        v = root->val;
        return ldr(root->right);
    }
};
