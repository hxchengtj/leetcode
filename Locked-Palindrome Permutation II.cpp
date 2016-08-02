class Solution {
public:
  vector<string> generatePalindromes(string s) {
    unordered_map<char, int> m;
    for(char c:s) m[c]++;
    vector<pair<char, int>> v;
    int cnt = 0;
    char mid;
    for(auto& p:m) {
      v.push_back({p.first, p.second/2});
      if (p.second&1) {
        cnt++;
        mid = p.first;
      }
    }
    if(cnt > 1) return {};
    vector<string> ans;
    string str;
    dfs(v, ans, str, s.size()/2);
    for(int i = 0; i < ans.size(); i++) {
      string t = ans[i];
      reverse(t.begin(), t.end());
      if(cnt) ans[i].push_back(mid);
      ans[i] += t;
    }
    return ans;
  }
  void dfs(vector<pair<char, int>>& v, vector<string>& ans, string& s, int n) {
    if(s.size() == n) {
      ans.push_back(s);
      return;
    }
    for(auto& p:v) {
      if(p.second > 0) {
        p.second--;
        s.push_back(p.first);
        dfs(v, ans, s, n);
        s.pop_back();
        p.second++;
      }
    }
  }
};
