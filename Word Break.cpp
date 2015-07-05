class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        int i, j, n = s.length(), k;
        vector<vector<bool> > f(n + 1);
        vector<bool> g(n+1);
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
        return g[n];
    }
};


//redo
class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        int n = s.size();
        vector<bool> f(n+1, false);
        f[0] = true;
        for(int i = 1; i <= n; i++)
            for(int j = 0; j < i; j++) {
                if(f[j] && wordDict.find(s.substr(j, i-j)) != wordDict.end()) {
                    f[i] = true;
                    break;
                }
            }
        return f[n];
    }
};