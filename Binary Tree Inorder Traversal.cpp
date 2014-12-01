/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 /*
class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> ans, v;
        if(root == NULL)
            return ans;
        ans = inorderTraversal(root->left);
        ans.push_back(root->val);
        v = inorderTraversal(root->right);
        ans.insert(ans.end(), v.begin(), v.end());
        return ans;
    }
};
*/
// iteratively
class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        stack<TreeNode *> s;
        vector<int> ans;
        TreeNode *t = root;
        while(t || !s.empty()) {
            if(t) {
                s.push(t);
                t = t->left;
            }
            else {
                t = s.top();
                ans.push_back(t->val);
                s.pop();
                t = t->right;
            }
        }
        return ans;
    }
};
