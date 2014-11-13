class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        int i, j, m = grid.size(), n = grid[0].size();
        int f[m+1][n+1];
        for(i = 0; i <= m; i++)
            f[i][0] = INT_MAX;
        for(i = 0; i <= n; i++)
            f[0][i] = INT_MAX;
        f[0][1] = 0;
        for(i = 1; i <= m; i++)
            for(j = 1; j <= n; j++)
                f[i][j] = min(f[i][j-1], f[i-1][j]) + grid[i-1][j-1];
        return f[m][n];
    }
};
