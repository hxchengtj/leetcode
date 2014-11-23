class Solution {
public:
    TreeNode *sortedArrayToBST(vector<int> &num) {
        return dfs(num, 0, num.size()-1);
    }
    TreeNode *dfs(vector<int> &num, int l, int r) {
        if(l > r)
            return NULL;
        int m = (l+r)/2;
        TreeNode *t = new TreeNode(num[m]);
        t->left = dfs(num, l, m-1);
        t->right = dfs(num, m+1, r);
        
    }
};