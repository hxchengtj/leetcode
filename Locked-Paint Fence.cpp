class Solution {
public:
  int numWays(int n, int k) { 
    if(n == 0 || k == 0) return 0;
    int f[2][2] = {{0, k}, {0, 0}};
    for(int i = 1; i < n; i++) {
      f[i&1][0] = f[(i+1)&1][1];
      f[i&1][1] = (f[(i+1)&1][1] + f[(i+1)&1][0]) * (k-1);
    }
    return (f[(n-1)&1][0] + f[(n-1)&1][1]);
  }
};
