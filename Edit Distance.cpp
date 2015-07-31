// review
// hard
class Solution {
public:
    int minDistance(string word1, string word2) {
        int f[word1.length()+1][word2.length()+1];
        int i, j;
        for(i = 0; i <= word1.length(); i++)
            for(j = 0; j <= word2.length(); j++) {
                if(i == 0 && j == 0)
                    f[i][j] = 0;
                else if(i > 0 && j > 0)
                    f[i][j] = min({f[i][j-1]+1, f[i-1][j]+1, f[i-1][j-1]+(word1[i-1] != word2[j-1])}); // 不要忘了{}
                else if(i > 0)
                    f[i][j] = f[i-1][j]+1;
                else
                    f[i][j] = f[i][j-1]+1;
            }
        return f[word1.length()][word2.length()];
    }
};

//redo
int minDistance(string word1, string word2) {
  int m = word1.size(), n = word2.size();
  int f[m+1][n+1];
  f[0][0] = 0;
  for(int i = 1; i <= m; i++) f[i][0] = i;
  for(int i = 1; i <= n; i++) f[0][i] = i;
  for(int i = 1; i <= m; i++)
    for(int j = 1; j <= n; j++)
      f[i][j] = min({1+f[i-1][j], 1+f[i][j-1], word1[i-1] == word2[j-1]? f[i-1][j-1]:f[i-1][j-1]+1});
  return f[m][n];
}

