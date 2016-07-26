class Solution {
public:
  vector<string> findStrobogrammatic(int n) {
    return dfs(n, true);
  }
  vector<string> dfs(int n, bool flag){
    if(n == 0) return {""};
    else if(n == 1) return {"0", "1", "8"};
    vector<string> ret = dfs(n-2, false);
    vector<string> ans;
    for(int i = flag?1:0; i < l.size(); i++)
      for(auto &s:ret) 
        ans.push_back(l[i]+s+r[i]);
    return ans;
  }
private:
  string l = "01689";
  string r = "01986";
};
