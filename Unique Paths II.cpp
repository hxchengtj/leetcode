class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        int f[m+1][n+1], i, j;
        for(i = 0; i <= m; i++)
            f[i][0] = 0;
        for(i = 0; i <= n; i++)
            f[0][i] = 0;
        f[0][1] = 1;
        for(i = 1; i <= m; i++)
            for(j = 1; j <= n; j++)
                if(obstacleGrid[i-1][j-1])
                    f[i][j] = 0;
                else
                    f[i][j] = f[i-1][j] + f[i][j-1];
        return f[m][n];
    }
};