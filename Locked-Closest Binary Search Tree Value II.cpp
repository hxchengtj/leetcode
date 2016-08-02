class Solution {
public:
  vector<int> closestKValues(TreeNode* root, double target, int k) {
    TreeNode* t = root;
    stack<TreeNode*> stk;
    queue<int> q;
    while(!stk.empty() || t) {
      while(t) {
        stk.push(t);
        t = t->left;
      }
      TreeNode* a = stk.top();
      stk.pop();
      if(q.size() < k) q.push(a->val);
      else if(abs(q.front() - target) > abs(a->val - target)) {
        q.pop();
        q.push(a->val);
      }
      t = a->right;
    }
    vector<int> ans;
    while(!q.empty()) {
      ans.push_back(q.front());
      q.pop();
    }
    return ans;
  }
};
