class Solution {
public:
    int minCut(string s) {
        int i, j, n = s.length();
        bool f[n+1][n+1];
        for(i = 0; i <= n; i++)
            for(j = 0; j + i <= n; j++) {
                if(i == 0 || i == 1) f[j][j+i] = true;
                else f[j][j+i] = f[j+1][j+i-1] && (s[j] == s[j+i-1]);
            }
        int g[n+1];
        g[0] = -1;
        g[1] = 0;
        for(i = 2; i <= n; i++) {
            g[i] = INT_MAX;
            for(j = 0; j < i; j++) 
                if(f[j][i])
                    g[i] = min(g[i], g[j]+1);
        }
        return g[n];
    }
};