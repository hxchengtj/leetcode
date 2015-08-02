class Solution {
public:
    vector<vector<int> > ans;
    vector<int> v;
    vector<bool> s;
    vector<vector<int> > permute(vector<int> &num) {
        ans.clear();
        v.clear();
        s.clear();
        v.resize(num.size());
        s.resize(num.size());
        dfs(0, num);
        return ans;
    }
    void dfs(int x, vector<int> &num) {
        if(x == num.size()) {
            ans.push_back(v);
            return;
        }
        for(int i = 0; i < num.size(); i++) {
            if(s[i] == false) {
                s[i] = true;
                v[x] = num[i];
                dfs(x+1, num);
                s[i] = false;
            }
        }
    }
};

//redo
vector<vector<int>> ans;
vector<int> v;
void __permute(vector<int>& nums, vector<bool>& visited, int n) {
  if(n == 0) {
    ans.push_back(v);
    return;
  }
  for(int i = 0; i < nums.size(); i++) {
    if(!visited[i]) {
      visited[i] = true;
      v.push_back(nums[i]);
      __permute(nums, visited, n-1);
      v.pop_back();
      visited[i] = false;
    }
  }
}
vector<vector<int>> permute(vector<int>& nums) {
  ans.clear(); v.clear();
  int n = nums.size();
  vector<bool> visited(n, false);
  __permute(nums, visited, n);
  return ans;
}

