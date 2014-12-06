 // review
class Solution {
public:
    int maxPathSum(TreeNode *root) {
        pair<int ,int> p;           //<最大路径，到达此点的最大路径>
        p = dfs(root);
        return p.first;
    }
    pair<int, int> dfs(TreeNode *root) {
        if(root == NULL)
            return make_pair(INT_MIN, 0);
        pair<int, int> l, r, ans;
        l = dfs(root->left);
        r = dfs(root->right);
        ans.second = max({root->val, l.second+root->val, r.second+root->val});
        ans.first = max({l.first, r.first, ans.second, root->val+l.second+r.second});
        return ans;
    }
};
