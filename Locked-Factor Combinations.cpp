class Solution {
public:
  vector<vector<int>> getFactors(int n) {
    vector<vector<int>> ans;
    vector<int> v;
    dfs(ans, v, 2, n);
    return ans;
  }
  void dfs(vector<vector<int>>& ans, vector<int>& v, int l, int n) {
    for(int i = l; i <= sqrt(n); i++) {
      if(n%i == 0) {
        v.push_back(i);
        v.push_back(n/i);
        ans.push_back(v);
        v.pop_back();
        dfs(ans, v, i, n/i);
        v.pop_back();
      }
    }
  }
};

