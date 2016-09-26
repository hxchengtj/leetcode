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

//version2
class Solution {
public:
    void dfs(string& low, string& high, string& s, int l, int r, int& cnt) {
        if(l > r) {
            if(s.size() == low.size() && s < low ||
               s.size() == high.size() && s > high) return;
            cnt++;
            return;
        }
        for(int i = 0; i < ls.size(); i++) {
            s[l] = ls[i];
            s[r] = rs[i];
            if(s[0] == '0' && s.size() > 1) continue;
            if(l < r || (l == r && ls[i] == rs[i])) 
                dfs(low, high, s, l+1, r-1, cnt);
        }
    }
    int strobogrammaticInRange(string low, string high) {
        int cnt = 0;
        for(int i = low.size(); i <= high.size(); i++) {
            string s(i, '0');
            dfs(low, high, s, 0, i-1, cnt);
        }
        return cnt;
    }
private:
    string ls = "01689";
    string rs = "01986";
};
