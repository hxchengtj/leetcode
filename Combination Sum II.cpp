class Solution {
public:
    vector<vector<int> > ans;
    vector<int> v;
    vector<int> s;
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        ans.clear();
        v.clear();
        s.clear();
        v.resize(num.size());
        s.resize(num.size());
        if(num.size() > 0) {
            s[num.size()-1] = 1;
            for(int i = num.size() - 2; i >= 0; i--)  //避免重复计算
                if(num[i] == num[i+1])
                    s[i] = s[i+1] + 1;
                else
                    s[i] = 1;
            dfs(0, 0, num, target);
        }
        return ans;
    }
    void dfs(int a, int now, vector<int> &num, int target) {
        if(target == 0) {
            vector<int> p(v.begin(), v.begin()+now);
            ans.push_back(p);
            return;
        }
        if(a >= num.size() || num[a] > target)
            return;
        for(int i = 0; i <= min(s[a], target/num[a]); i++) {
            if(i > 0)
                v[now+i-1] = num[a];
            dfs(a+s[a], now+i, num, target-num[a]*i);
        }
    }
};

//redo
vector<vector<int>> ans;
vector<int> v;
void dfs(vector<pair<int, int>> vp, int a, int target) {
  if(target == 0) {
    ans.push_back(v);
    return;
  }
  if(a >= vp.size() || target < 0) return;
  dfs(vp, a+1, target);
  for(int i = 0; i < vp[a].second; i++) {
    v.push_back(vp[a].first);
    target -= vp[a].first;
    dfs(vp, a+1, target);
  }
  v.resize(v.size()-vp[a].second);
}
vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
  if(candidates.size() == 0) return {};
  sort(candidates.begin(), candidates.end());
  ans.clear(); v.clear();
  vector<pair<int, int>> vp;
  vp.push_back(make_pair(candidates[0], 1));
  for(int i = 1; i < candidates.size(); i++)
    if(candidates[i] == candidates[i-1]) vp.back().second++;
    else vp.push_back(make_pair(candidates[i], 1));
  dfs(vp, 0, target);
  return ans;
}

