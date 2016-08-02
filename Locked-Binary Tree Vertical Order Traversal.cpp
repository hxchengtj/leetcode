class Solution {
public:
  vector<vector<int>> verticalOrder(TreeNode* root) {
    if(!root) return {};
    unordered_map<int, vector<int>> m;
    int min_col = 0;
    queue<pair<TreeNode*, int>> q;
    q.push({root, 0});
    while(!q.empty()) {
      auto t = q.front();
      q.pop();
      min_col = min(t.second, min_col);
      m[t.second].push_back((t.first)->val);
      if(t.first->left) q.push({t.first->left, t.second-1});
      if(t.first->right) q.push({t.first->right, t.second+1});
    }
    int i = min_col;
    vector<vector<int>> ans;
    while(m.find(i) != m.end()) {
      ans.push_back(m[i++]);
    }
    return ans;
  }
};
