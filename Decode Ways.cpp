// review
class Solution {
public:
    int numDecodings(string s) {
        if(!s.size())
            return 0;
        int i, f[s.size()+1];
        f[0] = 0;
        f[1] = 0;
        if(s[0] != '0') {           //*****
            f[0] = 1;
            f[1] = 1;
        }
        for(i = 1; i < s.size(); i++) {
            f[i+1] = 0;
            if(s[i-1] == '1' || (s[i-1] == '2' && s[i] >= '0' && s[i] <= '6') )
                f[i+1] += f[i-1];
            if(s[i] != '0')             // 0不能被表示
                f[i+1] += f[i];
        }
        return f[s.size()];
    }
};


//redo
int numDecodings(string s) {
  if(s.size() == 0) return 0;
  int f[2];
  f[0] = 1;
  f[1] = 0;
  if(s[0] != '0') f[1] = 1;
  for(int i = 1; i < s.size(); i++) {
    if (!( s[i-1] == '1' || (s[i-1] == '2' && s[i] >= 0 && s[i] <= '6') ))
      f[(i+1)%2] = 0;
    if(s[i] != '0') f[(i+1)%2] += f[i%2];
  }
  return f[s.size()%2];
}

