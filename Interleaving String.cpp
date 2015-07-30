class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s3.length() != s1.length() + s2.length())
            return false;
        int i, j;
        bool f[s3.length()+1][s1.length()+1];
        for(i = 0; i <= s3.length();i++)
            for(j = 0; j <= s1.length(); j++)
                f[i][j] = false;
        f[0][0] = true;
        for(i = 1; i <= s3.length(); i++)
            for(j = 0; j <= i && j <= s1.length(); j++)
                f[i][j] = (j >= 1 && f[i-1][j-1] && s1[j-1] == s3[i-1]) || ( i-j-1>= 0 && f[i-1][j] && s2[i-j-1] == s3[i-1]);
        for(i = 0; i <= s1.length(); i++)
            if(f[s3.length()][i])
                return true;
        return false;
    }
};


//redo
bool isInterleave(string s1, string s2, string s3) {
  int n1 = s1.size(), n2 = s2.size(), n3 = s3.size();
  if(n1+n2 != n3) return false;

  vector<vector<bool>> f(n3+1, vector<bool>(n1+1, false));
  f[0][0] = true;

  for(int i = 1; i <= n3; i++)
    for(int j = 0; j <= n1 && j <= i; j++)
      f[i][j] = (j >= 1 && f[i-1][j-1] && s3[i-1] == s1[j-1]) || (i-j >= 1 && f[i-1][j] && s3[i-1] == s2[i-j-1]);
  return f[n3][n1];
}

