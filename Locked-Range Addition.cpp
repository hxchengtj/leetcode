//redo
class Solution {
public:
  vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
    vector<int> ans(length);
    for(auto &v:updates) {
      ans[v[0]] += v[2];
      if(v[1] + 1 < length) ans[v[1]+1] -= v[2];
    }
    for(int i = 1; i < length; i++) ans[i] += ans[i-1];
    return ans;
  }
};

