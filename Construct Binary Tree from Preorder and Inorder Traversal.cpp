class Solution {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return dfs(preorder, 0, preorder.size()-1, inorder, 0, inorder.size());
    }
    TreeNode *dfs(vector<int> &preorder, int b1, int e1, vector<int> &inorder, int b2, int e2) {
        if(b1 > e1) 
            return NULL;
        TreeNode *t = new TreeNode(preorder[b1]);
        for(int i = b2; i <= e2; i++) {
            if(inorder[i] == preorder[b1]) {
                t->left = dfs(preorder, b1+1, b1+i-b2, inorder, b2, i-1);
                t->right = dfs(preorder, b1+i-b2+1, e1, inorder, i+1, e2);
                return t;
            }
        }
    }
};