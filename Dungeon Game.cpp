class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size(), n = dungeon[0].size();
        vector<int> v(n+1, INT_MAX);
        v[n-1] = 1;
        for(int i = m-1; i >= 0; i--)
            for(int j = n-1; j >= 0; j--)
                v[j] = max(min(v[j], v[j+1])-dungeon[i][j], 1);
        return v[0];
    }
};

//redo
int calculateMinimumHP(vector<vector<int>>& dungeon) {
  if(dungeon.size() == 0 || dungeon[0].size() == 0) return 0;
  int m = dungeon.size(), n = dungeon[0].size();
  vector<int> f(n+1, INT_MAX);
  f[n-1] = 1;
  for(int i = m-1; i >= 0; i--)
    for(int j = n-1; j >= 0; j--)
      f[j] = max(min(f[j], f[j+1])-dungeon[i][j], 1);
  return f[0];
}

