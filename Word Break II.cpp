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


