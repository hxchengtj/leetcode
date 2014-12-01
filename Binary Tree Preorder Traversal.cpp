class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        stack<TreeNode *> s;
        vector<int> ans;
        s.push(NULL);
        TreeNode *t = root;
        while(t != NULL) {
            ans.push_back(t->val);
            if(t->right != NULL)
                s.push(t->right);
            if(t->left != NULL) 
                t = t->left;
            else {
                t = s.top();
                s.pop();
            }
        }
        return ans;
    }
};
