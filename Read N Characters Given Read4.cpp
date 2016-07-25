class Solution {
public:
  int read(char *buf, int n) {
    char tmp[4];
    for(int i = 0; i < n; i += 4) {
      int l = read4(tmp);
      for(int j = i; j < min(n, i+l); j++) buf[j] = tmp[j-i];
      if(l < 4) return j;
    }
    return n;
  }
};
