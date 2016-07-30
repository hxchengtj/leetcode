class Solution {
public:
  int lengthOfLongestSubstringKDistinct(string s, int k) {
    unordered_map<char, int> m;
    int i = 0, ans = 0;
    for(int j = 0; j < s.size(); j++) {
      m[s[j]]++;
      while(m.size() > k) {
        m[s[i++]]--;
        if(m[s[i-1]] == 0) m.erase(s[i-1]);
      }
      ans = max(ans, j-i+1);
    }
    return ans;
  }
};
