int numSquares(int n) {
  if(n <= 0) return 0;
  vector<int> a;
  for(int i = 1;i*i <= n; i++)
    a.push_back(i*i);
  int f[n+1];
  f[0] = 0;
  for(int i = 1; i <= n; i++) {
    f[i] = INT_MAX;
    for(int j = 0; j < a.size() && a[j] <= i; j++)
      f[i] = min(f[i-a[j]]+1, f[i]);
  }
  return f[n];
}

