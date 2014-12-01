 //hard
// review
class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        stack<pair<TreeNode *, bool> > s;
        pair<TreeNode *, bool> p;
        vector<int> ans;
        TreeNode *t = root;
        while(!s.empty() || t) {
            while(t) {
                s.push(make_pair(t, false));
                t = t->left;
            }
            p = s.top();
            s.pop();
            t = p.first;
            if(p.second == false) {             //从左子树返回
                s.push(make_pair(t, true));
                t = t->right;
            }
            else {
                ans.push_back(t->val);
                t = NULL;
            }
        }
        return ans;
    }
};
