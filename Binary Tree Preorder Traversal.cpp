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


//redo
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root == NULL) return ans;
        stack<TreeNode*> stk;
        stk.push(root);
        while(!stk.empty()) {
            TreeNode* t = stk.top();
            stk.pop();
            ans.push_back(t->val);
            if(t->right) stk.push(t->right);
            if(t->left) stk.push(t->left);
        }
        return ans;
    }
};