class Solution {
public:
  bool isOneEditDistance(string s, string t) {
    int n = s.size(), m = t.size();
    if(abs(n-m) > 1) return false;
    if(n > m) return isOneDelete(s, t);
    else if(n < m) return isOneDelete(t, s);
    return s == t;
  }
  bool isOneDelete(string a, string b) {
    bool isDelete = false;
    int i = 0, j = 0, m = a.size(), n = b.size();
    while(j < n) {
      if(a[i] != b[j]) {
        if(isDelete) return false;
        isDelete = true;
        i++;
      } else {
        i++; j++;
      }
    }
    return true;
  }
};
