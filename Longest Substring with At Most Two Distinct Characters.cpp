class Solution {
public:
  int lengthOfLongestSubstringWithTwoDistinct(string s) {
    int n = s.size();
    unordered_map<char, int> m;
    int i = 0, j = 0, ans = 0;
    while(j < n) {
      if(m.size() == 2 && m.find(s[j]) == m.end()) {
        ans = max(j-i, ans);
        while(m.size() == 2) {
          m[s[i]]--;
          if(m[s[i]] == 0) m.erase(s[i]);
          i++;
        }
        m[s[j++]] = 1;
      } else m[s[j++]]++;
    }
    ans = max(j-i, ans);
    return ans;
  }
};
