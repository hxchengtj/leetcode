/* review again */
int hIndex(vector<int>& citations) {
  int n = citations.size();
  int count[n+1];
  memset(count, 0, sizeof(count));
  for(auto c:citations) count[min(c, n)]++;
  int a = 0;
  for(int i = n; i > 0; i--) {
    a += count[i];
    if(a >= i) return i;
  }
  return 0;
}

