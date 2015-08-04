class Solution {
public:
    int climbStairs(int n) {
        int f[n+3];
        f[1] = 1;
        f[2] = 2;
        for(int i = 3; i <= n; i++)
            f[i] = f[i-1] + f[i-2];
        return f[n];
    }
};

//redo
int climbStairs(int n) {
  int f[2];
  f[0] = 1; f[1] = 1;
  for(int i = 2; i <= n; i++)
    f[i%2] = f[i%2] + f[(i-1)%2];
  return f[n%2];
}

