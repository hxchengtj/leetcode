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

//redo
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
  if(obstacleGrid.size() == 0 || obstacleGrid[0].size() == 0 || obstacleGrid[0][0] == 1) return 0;
  int m = obstacleGrid.size(), n = obstacleGrid[0].size();
  int f[n+1];
  fill(f, f+n+1, 0);
  f[1] = 1;
  for(int i = 0; i < m; i++)
    for(int j = 0; j < n; j++)
      if(obstacleGrid[i][j] == 1) f[j+1] = 0;
      else f[j+1] = f[j+1] + f[j];
  return f[n];
}

