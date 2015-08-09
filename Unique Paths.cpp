class Solution {
public:
    int uniquePaths(int m, int n) {
        int f[m+1][n+1];
        int i, j;
        for(i = 0; i <= m; i++)
            f[i][0] = 0;
        for(j = 0; j <= n; j++)
            f[0][j] = 0;
        f[0][1] = 1;
        for(i = 1; i <= m; i++)
            for(j = 1; j <= n; j++)
                f[i][j] = f[i-1][j] + f[i][j-1];
        return f[m][n];
    }
};

//redo
int uniquePaths(int m, int n) {
  if(m == 0 || n == 0) return 0;
  int f[n+1];
  memset(f, 0, sizeof(f));
  f[1] = 1;
  for(int i = 0; i < m; i++)
    for(int j = 0; j < n; j++)
      f[j+1] = f[j]+f[j+1];
  return f[n];
}

