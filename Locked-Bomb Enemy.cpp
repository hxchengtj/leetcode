class Solution {
public:
  int maxKilledEnemies(vector<vector<char>>& grid) {
    if(grid.size() == 0 || grid[0].size() == 0) return 0;
    int m = grid.size(), n = grid[0].size(), row = 0, ans = 0;
    vector<int> col(n);
    for(int i = 0; i < m; i++)
      for(int j = 0; j < n; j++) {
        if(!j || grid[i][j] == 'W') {
          row = (grid[i][j] == 'E');
          for(int k = j+1; k < n && grid[i][k] != 'W'; k++)
            row += (grid[i][k] == 'E');
        }
        if(!i || grid[i][j] == 'W') {
          col[j] = (grid[i][j] == 'E');
          for(int k = i+1; k < m && grid[k][j] != 'W'; k++) 
            col[j] += (grid[k][j] == 'E');
        }
        if(grid[i][j] == '0') ans = max(ans, col[j]+row);
      }
    return ans;
  }
};
