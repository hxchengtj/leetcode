class Solution {
public:
  int minCost(vector<vector<int>>& costs) {
    int n = costs.size();
    int f[2][3];
    memset(f, 0, sizeof(f));
    for(int i = 0;i < costs.size(); i++) 
      for(int j = 0; j < 3; j++)
        f[i&1][j] = min(f[(i+1)&1][(j+1)%3], f[(i+1)&1][(j+2)%3])+costs[i][j];
    return min({f[(n+1)&1][0], f[(n+1)&1][1], f[(n+1)&1][2]});
    
  }
};
