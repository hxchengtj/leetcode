class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        vector<string> v;
        string t;
        int i, j, k, m = strlen(s), n = strlen(p);
        for(i = 0; i < n; i++) {
            if(p[i] == '*') {
                if(t.length())
                    v.push_back(t);
                v.push_back("*");
                t = "";
            }
            else
                t += p[i];
        }
        if(t.length())
            v.push_back(t);
        n = v.size();
        vector<bool> f(m+1);
        f[0] = true;
        for(i = 1; i <= n; i++) {
            if(v[i-1][0] == '*') {
                for(j = 1; j <= m; j++)
                    f[j] = f[j-1] || f[j];
            }
            else {
                k = v[i-1].length();
                for(j = m; j >= 0; j--) {
                    if(j >= k)
                        f[j] = f[j-k] && mystrcmp(v[i-1], s, j-k);
                    else
                        f[j] = false;
                }
            }
        }
        return f[m];

    }
    bool mystrcmp(string x, const char *s, int a) {
        for(int i = 0; i < x.size(); i++)
            if(x[i] == '?')
                continue;
            else if(x[i] != s[a+i])
                return false;
        return true;
    }
};



//version2
class Solution {
public:
    bool isMatch(string s, string p) {
        int ns = s.size(), np = p.size();
        if(np == 0) {
            if(ns == 0) return true;
            else return false;
        }
        int bs = 0, bp = 0;
        //写成具有自反性质的性质，这样在KMP算法中不会存在问题ß
        auto equalmatch = [](const char &a, const char &b){
            return a == b || a == '?' || b == '?';
        };
        for(int i = 0; i <= np; i++) {
            if(i == np || p[i] == '*') {
                while(bp < i && p[bp] == '*') bp++;
                if(bp < i) {
                    string::iterator it;
                    if(i == np)
                        it = search(s.begin() + max(bs, ns-i+bp), s.end(), p.begin()+bp, p.begin()+i, equalmatch);
                    else
                        it = search(s.begin()+bs, s.end(), p.begin()+bp, p.begin()+i, equalmatch);
                    if(it == s.end() || bp == 0 && it != s.begin()) return false;
                    bs = distance(s.begin(), it)+i-bp;
                }
                bp = i+1;
            }
        }
        return true;
    }
};

//redo
bool isMatch(string s, string p) {
  int ns = s.size(), np = p.size();
  if(np == 0) {
    if(ns == 0) return true;
    else return false;
  }
  auto cmp = [](const char & a, const char & b){
    return a == b || a == '?' || b == '?';
  };
  int si = 0, pi = 0;
  for(int i = 0; i <= np; i++) {
    if(i == np || p[i] == '*') {
      while(pi < i && p[pi] == '*') pi++;
      if(pi != i) {
        if(i == np) si = max(si, ns-np+pi);
        auto iter = search(s.begin()+si, s.end(), p.begin()+pi, p.begin()+i, cmp);
        if(iter == s.end() || (pi == 0 && iter != s.begin())) return false;
        si = distance(s.begin(), iter)+i-pi;
      }
      pi = i+1;
    }
  }
  return true;
}

