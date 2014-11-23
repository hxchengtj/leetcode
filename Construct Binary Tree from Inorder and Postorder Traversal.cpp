class Solution {
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        return dfs(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
    }
    TreeNode *dfs(vector<int> &inorder, int b1, int e1, vector<int> &postorder, int b2, int e2) {
        if(e1-b1 < 0)
            return NULL;
        TreeNode *t = new TreeNode(postorder[e2]);
        for(int i = b1; i <= e1; i++) {
            if(inorder[i] == postorder[e2]) {
                t->left = dfs(inorder, b1, i-1, postorder, b2, b2+i-1-b1);
                t->right = dfs(inorder, i+1, e1, postorder, b2+i-b1, e2-1);
                break;
            }
        }
        return t;
    }
};
};