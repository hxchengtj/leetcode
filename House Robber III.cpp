/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    pair<int, int> dfs(TreeNode* root) {
        pair<int, int> p(root->val, 0);
        if(root->left) {
            auto lp = dfs(root->left);
            p.first = max({p.first, lp.first, lp.second+p.first});
            p.second = max({p.second, p.second+lp.first});
        }
        if(root->right) {
            auto rp = dfs(root->right);
            p.first = max({p.first, rp.first, rp.second+p.first});
            p.second = max({p.second, p.second+rp.first});
        }
        p.first = max(p.first, p.second);
        return p;
    }
    int rob(TreeNode* root) {
        if(root == NULL) return 0;
        auto a = dfs(root);
        return max(a.first,a.second);
    }
};
