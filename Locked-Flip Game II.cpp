class Solution {
public:
  bool canWin(string s) {
    int n = s.size();
    for(int i = 0; i < n-1; i++) {
      if(s[i] == '+' && s[i+1] == '+' && !canWin(s.substr(0, i) + '-' + s.substr(i+2)))
        return true;
    }
    return false;
  }
};
