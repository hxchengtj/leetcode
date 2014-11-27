class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        queue<TreeNode *> q1, q2;
        TreeNode *l;
        if(root)
            q1.push(root);
        vector<vector<int> > ans;
        vector<int> v;
        while(!q1.empty() || !q2.empty()) {
            v.clear();
            while(!q1.empty()) {
                l = q1.front();
                v.push_back(l->val);
                if(l->left)
                    q2.push(l->left);
                if(l->right)
                    q2.push(l->right);
                q1.pop();
            }
            if(v.size())
                ans.push_back(v);
            v.clear();
            while(!q2.empty()) {
                l = q2.front();
                v.push_back(l->val);
                if(l->left)
                    q1.push(l->left);
                if(l->right)
                    q1.push(l->right);
                q2.pop();
            }
            if(v.size())
                ans.push_back(v);
        }
        return ans;
    }
};
