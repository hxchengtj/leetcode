class Solution {
public:
    int getMoneyAmount(int n) {
        int f[n+1][n+1];
        memset(f, 0, sizeof(f));
        for(int i = 0; i < n-1; i++) f[i][i+2] = i+1;
        for(int i = 3; i <= n; i++) 
            for(int j = 0; j+i <= n; j++) {
                f[j][i+j] = INT_MAX;
                for(int k = j; k < i+j; k++) 
                    f[j][i+j] = min(f[j][i+j], max(f[j][k], f[k+1][i+j])+(k+1));
            }
        return f[0][n];
    }
};
