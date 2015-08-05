class Solution {
public:
    vector<vector<int> > ans;
    vector<int> v;
    vector<vector<int>> combinationSum3(int k, int n) {
        ans.clear();
        v.clear();
        dfs(k, n, 1);
        return ans;
    }
    void dfs(int k, int n, int a) {
        if(k <= 1) {
            if(n >= a && n <= 9 && n >= 1) {
                v.push_back(n);
                ans.push_back(v);
                v.pop_back();
            }
            return;
        }
        for(int i = a; i <= 9; i++) {
            v.push_back(i);
            dfs(k-1, n-i, i+1);
            v.pop_back();
        }
    }
};


//redo
vector<vector<int>> ans;
vector<int> v;
vector<vector<int>> combinationSum3(int k, int n) {
  ans.clear(); v.clear();
  if(k == 0) return ans;
  dfs(1, k, n);
  return ans;
}

void dfs(int a, int k, int n) {
  if(k == 1) {
    if(n >= a && n <= 9) {
      v.push_back(n);
      ans.push_back(v);
      v.pop_back();
    }
    return;
  }
  for(int i = a; i <= min(n, 9); i++) {
    v.push_back(i);
    dfs(i+1, k-1, n-i);
    v.pop_back();
  }
}

