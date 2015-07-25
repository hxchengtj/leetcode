class Solution {
public:
    vector<vector<int> > ans;
    vector<int> v;
    vector<vector<int> > subsets(vector<int> &S) {
        sort(S.begin(), S.end());
        dfs(0, S);
        return ans;
    }
    void dfs(int a, vector<int> &S) {
        if(a >= S.size()) {
            ans.push_back(v);
            return;
        }
        if(a > 0 && S[a] == S[a-1]) {
            dfs(a+1, S);
            return;
        }
        v.push_back(S[a]);
        dfs(a+1, S);
        v.pop_back();
        dfs(a+1, S);
    }
};

//redo
void dfs(vector<int>& nums, int l, vector<vector<int>>& ans, vector<int>& v) {
  if(l == nums.size()) {
    ans.push_back(v);
    return;
  }
  v.push_back(nums[l]);
  dfs(nums, l+1, ans, v);
  v.pop_back();
  dfs(nums, l+1, ans, v);
}
vector<vector<int>> subsets(vector<int>& nums) {
  sort(nums.begin(), nums.end());
  vector<vector<int>> ans;
  vector<int> v;
  dfs(nums, 0, ans, v);
  return ans;
}

