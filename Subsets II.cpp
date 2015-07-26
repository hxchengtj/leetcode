class Solution {
public:
    vector<vector<int> > ans;
    vector<int> b;
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        sort(S.begin(), S.end());
        vector<pair<int, int> > v;
        int i;
        v.push_back(make_pair(S[0], 1));
        for(i = 1; i < S.size(); i++) {
            if(S[i] == S[i-1])
                v.back().second++;
            else
                v.push_back(make_pair(S[i], 1));
        }
        dfs(0, v);
        return ans;
    }
    void dfs(int a, vector<pair<int, int> > &v) {
        if(a >= v.size()) {
            ans.push_back(b);
            return;
        }
        int i;
        for(i = 0; i <= v[a].second; i++) {
            dfs(a+1, v);
            b.push_back(v[a].first);
        }
        for(i = 0; i <= v[a].second; i++)
            b.pop_back();
    }
};


//redo
vector<vector<int> > ans;
vector<int> v;
void dfs(vector<pair<int, int>>& numv, int l) {
  if(l >= numv.size()) {
    ans.push_back(v);
    return;
  }
  for(int i = 0; i <= numv[l].second; i++) {
    dfs(numv, l+1);
    if(i < numv[l].second) v.push_back(numv[l].first);
  }
  v.resize(v.size()-numv[l].second);
}
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
  ans.clear();
  v.clear();
  sort(nums.begin(), nums.end());
  vector<pair<int, int> > numv;
  int n = nums.size(), m = 1;
  for(int i = 1; i <= nums.size(); i++) {
    if(i == nums.size() || nums[i] != nums[i-1]) {
      numv.push_back(make_pair(nums[i-1], m));
      m = 1;
    } else m++;
  }
  dfs(numv, 0);
  return ans;
}

