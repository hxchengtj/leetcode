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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> v;
        if(root == NULL)
            return v;
        q.push(root);
        q.push(NULL);
        TreeNode *t;
        bool flag = true;
        while(!q.empty()) {
            t = q.front();
            if(t == NULL) {
                flag = true;
                if(q.back() != NULL)
                    q.push(NULL);
            }
            else {
                if(flag)
                    v.push_back(t->val);
                flag = false;
                if(t->right)
                    q.push(t->right);
                if(t->left)
                    q.push(t->left);
            }
            q.pop();
        }
        return v;
    }
};