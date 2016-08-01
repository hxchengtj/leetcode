class Solution {
public:
  int minTotalDistance(vector<vector<int>>& grid) {
    if(grid.size() == 0 || grid[0].size() == 0) return 0;
    int m = grid.size(), n = grid[0].size();
    vector<int> x, y;
    for(int i = 0; i < m; i++)
      for(int j = 0; j < n; j++)
        if(grid[i][j] == 1) {
          x.push_back(i);
          y.push_back(j);
        }
    if(x.size() == 0) return 0;
    int midx = x[x.size()/2];
    nth_element(y.begin(), y.begin()+y.size()/2, y.end());
    int midy = y[y.size()/2];
    int dis = 0;
    for(int i = 0; i < x.size(); i++) {
      dis += abs(x[i]-midx);
      dis += abs(y[i]-midy);
    }
    return dis;
  }
};
