class Solution {
public:
  vector<string> generateAbbreviations(string word) {
    vector<string> ans;
    string s;
    dfs(ans, s, word, 0, 0);
    return ans;
  }
  void dfs(vector<string> & ans, string & s, string & word, int cnt, int i) {
    int n = s.size();
    if(i >= word.size()) {
      if(cnt > 0) s += to_string(cnt);
      ans.push_back(s);
    } else {
      dfs(ans, s, word, cnt+1, i+1);
      s += cnt?to_string(cnt):"";
      s.push_back(word[i]);
      dfs(ans, s, word, 0, i+1);
    }
    s.resize(n);
  }
};

