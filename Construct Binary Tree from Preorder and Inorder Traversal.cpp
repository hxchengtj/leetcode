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

//redo
class Solution {
public:
    TreeNode* __buildTree(vector<int>& preorder, vector<int>& inorder, unordered_map<int, int> &m, int bp, int bi, int n) {
        if(n == 0) return NULL;
        TreeNode *root = new TreeNode(preorder[bp]);
        int k = m[preorder[bp]]-bi;
        root->left = __buildTree(preorder, inorder, m, bp+1, bi, k);
        root->right = __buildTree(preorder, inorder, m, bp+1+k, bi+1+k, n-k-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> m;
        for(int i = 0; i < inorder.size(); i++)
            m[inorder[i]] = i;
        return __buildTree(preorder, inorder, m, 0, 0, preorder.size());
    }
};