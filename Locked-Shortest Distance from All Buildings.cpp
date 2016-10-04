/* review again */
class Solution {
public:
  int shortestDistance(vector<vector<int>> grid) {
    if(grid.size() == 0 || grid[0].size() == 0) return 0;
    int m = grid.size(), n = grid[0].size(), a = 0, ans = -1;
    vector<vector<int>> tot_dis(m, vector<int>(n));
    int f[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    for(int i = 0; i < m; i++)
      for(int j = 0; j < n; j++) {
        if(grid[i][j] == 1) {
          vector<vector<int>> dis(m, vector<int>(n));
          ans = -1;
          queue<pair<int, int>> q;
          q.push(make_pair(i, j));
          while(!q.empty()) {
            auto t = q.front();
            q.pop();
            for(int i = 0; i < 4; i++) {
              int ii = t.first+f[i][0], jj = t.second+f[i][1];
              if(ii >= 0 && ii < m && jj >= 0 && jj < n && grid[ii][jj] == a) {
                q.push(make_pair(ii, jj));
                grid[ii][jj]--;
                dis[ii][jj] = dis[t.first][t.second]+1;
                tot_dis[ii][jj] += dis[ii][jj];
                if(ans < 0 || ans > tot_dis[ii][jj]) ans = tot_dis[ii][jj];
              }
            }
          }
          a--;
        }
      }
    return ans;
  }
};

