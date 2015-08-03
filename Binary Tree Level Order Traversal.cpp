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

//redo
vector<vector<int>> leverOrder(TreeNode* root) {
  vector<vector<int>> ans;
  vector<int> v;
  if(root == NULL) return ans;
  queue<TreeNode*> q;
  q.push(root);
  q.push(NULL);
  while(!q.empty()) {
    TreeNode* t = q.front();
    q.pop();
    if(t == NULL) {
      ans.push_back(v);
      v.clear();
      if(!q.empty()) q.push(NULL);
    }
    else {
      v.push_back(t->val);
      if(t->left) q.push(t->left);
      if(t->right) q.push(t->right);
    }
  }
  return ans;
}

