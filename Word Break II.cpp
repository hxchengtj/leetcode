class Solution {
public:
    vector<string> ans;
    string a;
    vector<vector<bool> > f;
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        int i, j, n = s.length(), k;
        vector<bool> g(n+1);
        f.resize(n+1);
        for(i = 0; i <= n; i++)
            f[i].resize(n+1);
        f[0][0] = true;
        g[0] = true;
        for(i = 1; i <= n; i++)
            for(j = 1; j <= i; j++) {
                if(dict.find(s.substr(i-j, j)) != dict.end())
                    f[i][j] = g[i-j];
                g[i] = g[i] || f[i][j];
            }
        dfs(s, n);
        return ans;
    }
    void dfs(string &s, int n) {
        if(n == 0) {
            ans.push_back(a);
            return;
        }
        for(int i = 1; i <= n; i++)
            if(f[n][i]) {
                if(a.length())
                    a = s.substr(n-i, i) + " " + a;
                else
                    a = s.substr(n-i, i);
                dfs(s, n-i);
                a.erase(a.begin(), a.begin()+i);
                if(a.length())
                    a.erase(a.begin(), a.begin()+1);
            }
    }
};


//version2
class Solution {
public:
    bool __wordBreak(string s, unordered_set<string>& wordDict, vector<bool> &f, int b, string &sen, vector<string> &ans) {
        if(b == s.size()) {
            ans.push_back(sen);
            return true;
        }
        if(f[b] == false) return false;
        bool flag = false;
        for(int i = b+1; i <= s.size(); i++) {
            string w = s.substr(b, i-b);
            if(wordDict.find(w) != wordDict.end()) {
                int a = sen.size();
                if(a > 0) sen.push_back(' ');
                sen.append(w);
                // || 不可以是因为 || 的优化 flag为true不执行下一步
                flag = (flag | __wordBreak(s, wordDict, f, i, sen, ans));
                sen.resize(a);
            }
        }
        f[b] = flag;
        return flag;
    }
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        vector<string> ans;
        int n = s.size();
        vector<bool> f(n, true);
        string sen;
        __wordBreak(s, wordDict, f, 0, sen, ans);
        return ans;
    }
};

//version2
//redo
bool __wordbreak(string &s, unordered_set<string> & wordDict, int l, vector<bool> &f, string &a, vector<string> &ans) {
  if(l == s.size()) {
    ans.push_back(a);
    return true;
  }

  if(!f[l]) return false;
  bool flag = false;
  int as = a.size();
  for(int i = l+1; i <= s.size(); i++) {
    string t = s.substr(l, i-l);
    if(wordDict.find(t) != wordDict.end()) {
      if(a) a.append(" "+t);
      else a.append(t);
      flag |= __wordbreak(s, wordDict, i, f, a, ans);
      a.resize(as);
    }
  }
  f[l] = flag;
  return flag;
}
vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
  vector<string> ans;
  int n = s.size();
  if(n == 0) return ans;
  vector<bool> f(n, true);
  string a;
  __wordbreak(s, wordDict, 0, f, a, ans);
  return ans;
}

