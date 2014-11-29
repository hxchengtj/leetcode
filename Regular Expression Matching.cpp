class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        vector<string> v;
        string t, x;
        int i, j, k, m = strlen(s), n = strlen(p);
        for(i = 0; i < n; i++) {
            if(p[i] == '*') {
                x = t.back();
                t.pop_back();
                v.push_back(t);
                v.push_back(p[i]+x);
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
                    f[j] = f[j] || (f[j-1] && (s[j-1] == v[i-1][1] || v[i-1][1] == '.'));
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
    bool mystrcmp(string x, const char* s, int a) {
        for(int i = 0; i < x.length(); i++) {
            if(x[i] == '.')
                continue;
            else if(x[i] != s[i+a])
                return false;
        }
        return true;
    }
};