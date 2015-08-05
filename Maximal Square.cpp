class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0)
            return 0;
        int m = matrix.size(), n = matrix[0].size();

        int f[m][n];
        int maxf = 0;
        for(int i = 0; i < n; i++) {
            if(matrix[0][i] == '1') {
                f[0][i] = 1;
                maxf = 1;
            }
            else
                f[0][i] = 0;
        }
        for(int i = 0; i < m; i++) {
            if(matrix[i][0] == '1') {
                f[i][0] = 1;
                maxf = 1;
            }
            else
                f[i][0] = 0;
        }
        for(int i = 1; i < m; i++)
            for(int j = 1; j < n; j++) {
                if(matrix[i][j] == '1') {
                    f[i][j] = min(min(f[i-1][j-1], f[i][j-1]), f[i-1][j])+1;
                    maxf = max(maxf, f[i][j]);
                }
                else
                    f[i][j] = 0;
            }
        return maxf*maxf;
    }
};

//redo
int maximalSquare(vector<vector<char>>& matrix) {
  if(matrix.size() == 0 || matrix[0].size() == 0) return 0;
  int m = matrix.size(), n = matrix[0].size();
  vector<vector<int>> f(2, vector<int>(n+1, 0));
  int maxf = 0;
  for(int i = 0; i < m; i++)
    for(int j = 0; j < n; j++) {
      if(matrix[i][j] == '0') f[i%2][j+1] = 0;
      else {
        f[i%2][j+1] = min({f[(i+1)%2][j], f[(i+1)%2][j+1], f[i%2][j]})+1;
        maxf = max(maxf, f[i%2][j+1]);
      }
    }
  return maxf*maxf;
}

