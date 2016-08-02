class Solution {
public:
  int minCostII(vector<vector<int>>& costs) {
    if(costs.size() == 0 || costs[0].size() == 0) return 0;
    int n = costs.size(), k = costs[0].size();
    int f[2][k];
    memset(f, 0, sizeof(f));
    int min1 = 0, min2 = 0;
    for(int i = 0; i < n; i++) {
      int id1 = min1, id2 = min2;
      min1 = -1, min2 = -1;
      for(int j = 0; j < k; j++) {
        f[i&1][j] = costs[i][j] + (id1 == j?f[(i+1)&1][id2]:f[(i+1)&1][id1]); 
        if (min1 < 0 || f[i&1][min1] > f[i&1][j]) {
          min2 = min1; min1 = j; //前后顺序很重要
        } else if(min2 < 0 || f[i&1][min2] > f[i&1][j])
          min2 = j;
      }
    }
    return f[(n+1)&1][min1];
  }
};
