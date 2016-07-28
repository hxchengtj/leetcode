class Solution {
public:
  int strobogrammaticInRange(string low, string high) {
    int count = 0;
    string s = "";
    for(int i = low.size(); i <= high.size(); i++) {
      s.resize(i);
      dfs(s, 0, i-1, low, high, count);
    }
    return count;
  }
  void dfs(string& s, int l, int r, string &low, string & high, int & cnt) {
    if(l > r) {
      if( (s.size() == low.size() && s < low) || (s.size() == high.size() && s > high)) return;
      cnt++;
      return;
    }
    for(int i = l == 0?1:0; i < lnum.size(); i++) {
      s[l] = lnum[i];
      s[r] = rnum[i];
      if(l != r || (l == r && s[l] == s[r])) dfs(s, l+1, r-1, low, high, cnt);
    }
  }
private:
  string lnum = "01689";
  string rnum = "01968";
};
