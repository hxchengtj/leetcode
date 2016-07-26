class Solution {
public:
  int shortestWordDistance(vector<string>& words, string word1, string word2) {
    int j = -1, k = -1, ans = INT_MAX;
    bool isSame = (word1 == word2);
    for(int i = 0; i < words.size(); i++) {
      if(words[i] == word1) {
        if(isSame) k = j;
        j = i;
      } else if(words[i] == word2) k = i;
      if(j != -1 && k != -1) ans = min(ans, abs(k-j));
    }
    return ans;
  }
};
