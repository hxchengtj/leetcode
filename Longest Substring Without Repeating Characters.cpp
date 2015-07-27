class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i, a[256], maxl = 0, j, k;
        for(i = 0; i < 256; i++)
            a[i] = -1;
        k = 0;
        for(i = 0; i < s.length(); i++) {
            j = s[i];
            if(a[j] >= k) {
                maxl = max(maxl, i-k);
                k = a[j]+1;
            }
            a[j] = i;
        }
        maxl = max(maxl, i-k);
        return maxl;
    }
};

//redo
int lengthOfLongestSubstring(string s) {
  int n = s.size(), l = 0, r = 0, ans = 0;
  unordered_set<char> sc;
  while(r < n) {
    if(sc.find(s[r]) != sc.end()) sc.erase(s[l++]);
    else {
      sc.insert(s[r++]);
      ans = max(ans, r-l);
    }
  }
  return ans;
}

