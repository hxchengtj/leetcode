/* review again */
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


//redo
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> stk;
        TreeNode* pre = NULL;
        TreeNode* p = root;
        while(p || !stk.empty()) {
            while(p) {
                stk.push(p);
                p = p->left;
            }
            TreeNode* t = stk.top();
            if(t->right == NULL || pre == t->right) {
                stk.pop();
                ans.push_back(t->val);
                pre = t;
            }
            else p = t->right;
        }
        return ans;
    }
};


//redo2
vector<int> postorderTraversal(TreeNode* root) {
  TreeNode* p = root, *pre = NULL;
  stack<TreeNode*> stk;
  vector<int> ans;
  while(p || !stk.empty()) {
    while(p) {
      stk.push(p);
      p = p->left;
    }
    TreeNode* t = stk.top();
    if(t->right == NULL || pre == t->right) {
      ans.push_back(t->val);
      stk.pop();
      pre = t;
    }
    else p = t->right;
  }
  return ans;
}

