class Solution {
public:
    vector<string> v;
    vector<vector<string> > ans;
    vector<vector<string>> partition(string s) {
        dfs(0, s);
        return ans;
    }
    void dfs(int x, string &s) {
        if(x >= s.length()) {
            ans.push_back(v);
            return;
        }
        for(int i = x; i < s.size(); i++) {
            int l = x;
            int r = i;
            while(l < r) {
                if(s[l] != s[r])
                    break;
                l++;
                r--;
            }
            if(l >= r) {
                v.push_back(s.substr(x, i-x+1));
                dfs(i+1, s);
                v.pop_back();
            }
        }
    }
};


//redo
vector<vector<string>> ans;
vector<string> v;
vector<vector<string>> partition(string s) {
  ans.clear(); v.clear();
  int n = s.size();
  if(n == 0) return ans;
  vector<vector<bool>> isP(n+1, vector<bool>(n+1, false));
  vector<bool> f(n, true);
  for(int i = 0; i <= n; i++)
    for(int j = 0; j+i <= n; j++) {
      if(i < 2) isP[j][i+j] = true;
      else isP[j][i+j] = (s[j] == s[i+j-1]) && isP[j+1][i+j-1];
    }
  dfs(s, 0, isP, f);
  return ans;
}

bool dfs(string& s, int l, vector<vector<bool>>& isP, vector<bool>& f) {
  if(l == s.size()) {
    ans.push_back(v);
    return true;
  }
  if(!f[l]) return false;

  bool flag = false;
  for(int i = l+1; i <= s.size(); i++) {
    if(isP[l][i]) {
      v.push_back(s.substr(l, i-l));
      flag |= dfs(s, i, isP, f);
      v.pop_back();
    }
  }
  f[l] = flag;
  return flag;
}

