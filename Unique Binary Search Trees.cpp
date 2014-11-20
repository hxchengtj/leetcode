class Solution {
public:
    int numTrees(int n) {
        int i, j, f[n+1];
        f[0] = 1;
        f[1] = 1;
        for(i = 2; i <= n; i++) {
            f[i] = 0;
            for(j = 0; j < i; j++)
                f[i] += f[j] * f[i-1-j];
        }
        return f[n];
    }
};
