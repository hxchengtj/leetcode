class Solution {
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        stack<TreeNode *> s1, s2;
        vector<int> v;
        vector<vector<int> > ans;
        s1.push(root);
        while(!s1.empty() || !s2.empty()) {
            while(!s1.empty()) {
                if(s1.top() != NULL) {
                    v.push_back(s1.top()->val);
                    s2.push(s1.top()->left);
                    s2.push(s1.top()->right);
                }
                s1.pop();
            }
            if(v.size())
                ans.push_back(v);
            v.clear();
            while(!s2.empty()) {
                if(s2.top() != NULL) {
                    v.push_back(s2.top()->val);
                    s1.push(s2.top()->right);
                    s1.push(s2.top()->left);
                }
                s2.pop();
            }
            if(v.size())
                ans.push_back(v);
            v.clear();
        }
        return ans;
    }
};


//redo
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
  vector<vector<int>> ans;
  vector<int> v;
  if(root == NULL) return ans;
  int k = 0;
  queue<TreeNode*> q;
  q.push(root);
  q.push(NULL);
  while(!q.empty()) {
    TreeNode* t = q.front();
    q.pop();
    if(t == NULL) {
      if(k == 1) reverse(v.begin(), v.end());
      k = (k+1)%2;
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

