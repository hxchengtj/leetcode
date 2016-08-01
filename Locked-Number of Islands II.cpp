class Solution {
public:
  vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
    father.clear();
    father.resize(m*n);
    for(int i = 0; i < m*n; i++) father[i] = -1;
    vector<int> ans;
    int cnt = 0;
    int f[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    for(auto& p:positions) {
      int id = p.first * n + p.second;
      if(father[id] != -1) continue;
      father[id] = id;
      cnt++;
      for(int i = 0; i < 4; i++) {
        int x = p.first + f[i][0], y = p.second - f[i][1];
        if(x >= 0 && x < m && y >= 0 && y < n && father[x*n+y] != -1) {
          int id2 = x*n+y;
          int fa = find_father(id), fb = find_father(id2);
          if(fa != fb) {
            cnt--;
            father[fa] = fb; 
          }
        }
      }
      ans.push_back(cnt);
    }
    return ans;
  }
  int find_father(int id) {
    if(father[id] != id) father[id] = find_father(father[id]);
    return father[id];
  }
private:
  vector<int> father; 
};
