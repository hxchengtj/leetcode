class Solution {
public:
  void reverseWords(string &s) {
    reverse(s.begin(), s.end());
    int j = 0;
    for(int i = 0; i <= s.size(); i++) {
      if(i == s.size() || s[i] == ' ') {
        reverse(s.begin()+j, s.begin()+i);
        j = i+1;
      }
    }
  }
};
