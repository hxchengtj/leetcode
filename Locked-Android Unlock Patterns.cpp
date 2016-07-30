class Solution {
public:
  int numberOfPatterns(int m, int n) {
    vector<bool> visited(10);
    int ans = 0;
    ans += dfs(1, 1, 0, m, n, visited) * 4;
    ans += dfs(2, 1, 0, m, n, visited) * 4;
    ans += dfs(5, 1, 0, m, n, visited);
    return ans;
  }
  int dfs(int a, int l, int cnt, int m, int n, vector<bool> & visited) {
    if(l >= m && l <= n) cnt++;
    if(l >= n) return cnt;
    visited[a] = true;
    for(int i = 1; i <= 9; i++) {
      int b = jump(a, i);
      if(!visited[i] && (b == -1 || visited[b])) {
        cnt = dfs(i, l+1, cnt, m, n, visited);
      }
    }
    visited[a] = false;
    return cnt;
  }

  int jump(int a, int b) {
    a--; b--;
    int i1 = a/3, i2 = b/3, j1 = a%3, j2 = b%3;
    if ((i1+i2)%2 == 0 && (j1+j2)%2 == 0) return ((i1+i2)/2*3+(j1+j2)/2+1);
    else return -1;
  }
};
