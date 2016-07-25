class Solution {
public:
  int read(char *buf, int n) {
    int i = 0;
    while(i < n && !remain.empty()) {
      buf[i++] = remain.front();
      remain.pop();
    }
    char tmp[4];
    for(; i < n; i += 4) {
      int l = read4(tmp), j;
      for(j = 0; j < min(n-i, l); j++) buf[i+j] = tmp[j];
      int k = i+j;
      for(; j < l; j++) remain.push(tmp[j]);
      if (l < 4) return k;
    }
    return n;
  }
private:
  queue<char> remain;
};

