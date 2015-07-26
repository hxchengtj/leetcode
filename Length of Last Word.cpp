class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int n = strlen(s), i = n-1, j = 0;
        while(s[i] == ' ')
            i--;
        for(; s[i] != 0 && s[i] != ' '; i--)
            j++;
        return j;
    }
};

//redo
int lengthOfLastWord(string s) {
  int ans = 0, n = s.size();
  for(int i = n-1; i >= 0; i--) {
    if(s[i] == ' ' && ans != 0) break;
    else if(s[i] != ' ') ans++;
  }
  return ans;
}

