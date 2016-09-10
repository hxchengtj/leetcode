/* review again */
//hard
class Solution {
public:
    bool isScramble(string s1, string s2) {
        if(s1.length() != s2.length())
            return false;
        if(s1.length() == 0)
            return true;
        bool f[s1.length()][s2.length()][s1.length()+1];
        int i, j, k, l;
        for(k = 1; k <= s1.length(); k++)
            for(i = 0; i <= s1.length() - k; i++)
                for(j = 0; j <= s2.length() - k; j++) {
                    if(k == 1) {
                        if(s1[i] == s2[j])
                           f[i][j][k] = true;
                        else
                            f[i][j][k] = false;
                    }
                    else {
                        f[i][j][k] = false;
                        for(l = 1; l < k; l++){
                            if(f[i][j][k])
                                break;
                            f[i][j][k] = (f[i][j][l] && f[i+l][j+l][k-l]) || (f[i][j+k-l][l] && f[i+l][j][k-l]);
                        }
                    }
                }

        return f[0][0][s1.length()];

    }
};

//redo
bool isScramble(string s1, string s2) {
  if(s1 == s2) return true;
  string ss1(s1), ss2(s2);
  sort(ss1.begin(), ss1.end());
  sort(ss2.begin(), ss2.end());
  if(ss1 != ss2) return false;
  int n = s1.size();
  for(int i = 1; i < n; i++) {
    if((isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i, n-i), s2.substr(i, n-i))) ||
           (isScramble(s1.substr(0, i), s2.substr(n-i, i)) && isScramble(s1.substr(i, n-i), s2.substr(0, n-i))) )
      return true;
  }
  return false;
}

