class Solution {
public:
    int depth(TreeNode *root) {
        if(root == NULL)
            return 0;
        int ldepth, rdepth;
        ldepth = depth(root->left);
        if(ldepth == -1)
            return -1;
        rdepth = depth(root->right);
        if(rdepth == -1)
            return -1;
        if(abs(ldepth-rdepth) > 1)
            return -1;
        return max(ldepth, rdepth)+1;
    }
    bool isBalanced(TreeNode *root) {
        if(depth(root) == -1)
            return 0;
        return 1;
    }

};
