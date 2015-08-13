class Solution {
public:
    string convert(string s, int nRows) {
        string ans;
        int i, j, k;
        int f[2];
        if(nRows <= 1)
            return s;
        for(i = 0; i < nRows; i++) {
             f[0] = 2*(nRows-i-1);
             f[1] = 2*i;
             j = i;
             k = 0;
             while(j < s.length()) {
                 ans += s[j];
                 if(f[k] == 0)
                    k = (k+1)%2;
                j += f[k];
                k = (k+1)%2;
             }
        }
        return ans;
    }
};

//redo
string convert(string s, int numRows) {
  if(numRows <= 1) return s;
  int f[2];
  string ans;
  int n = s.size();
  for(int i = 0; i < numRows; i++) {
    f[0] = 2*(numRows-i-1);
    f[1] = 2*i;
    if(f[0] == 0) f[0] = f[1];
    if(f[1] == 0) f[1] = f[0];
    int j = i, k = 0;
    while(j < n) {
      ans.push_back(s[j]);
      j += f[k];
      k = (k+1)%2;
    }
  }
  return ans;
}

