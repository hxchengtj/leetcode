class Solution {
public:
  void wallsAndGates(vector<vector<int>>& rooms) {
    if(rooms.size() == 0 || rooms[0].size() == 0) return;
    int m = rooms.size(), n = rooms[0].size();
    int f[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    for(int i = 0; i < m; i++)
      for(int j = 0; j < n; j++) 
        if(rooms[i][j] == 0) {
          queue<pair<int, int>> q;
          unordered_map<int, int> MAP;
          q.push({i, j});
          MAP[i*n+j] = 0;
          while(!q.empty()) {
            auto t = q.front();
            q.pop();
            for(int k = 0; k < 4; k++) {
              int ii = t.first + f[k][0], jj = t.second + f[k][1];
              if(ii >=0 && ii < m && jj >= 0 && jj < n && rooms[ii][jj] > 0 && MAP.find(ii*n+jj) == MAP.end()) {
                MAP[ii*n+jj] = MAP[t.first*n+t.second]+1;
                q.push({ii, jj});
                rooms[ii][jj] = min(rooms[ii][jj], MAP[ii*n+jj]);
              }
            }
          }
        }
    }
};
