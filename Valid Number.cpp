/* review again */
// review
// ><....
class Solution {
public:
    bool isNumber(const char *s) {
        int i;
        bool l = false, r = false;
        i = 0;
        while(s[i] == ' ')
            i++;
        if(!s[i])
            return false;
        if(s[i] == '-' || s[i] == '+')
            i++;
        while(s[i] >= '0' && s[i] <= '9') {
            l = true;
            i++;
        }
        if(s[i] == '.') {
            i++;
            while(s[i] >= '0' && s[i] <= '9') {
                r = true;
                i++;
            }
            if(!l && !r)
                return false;
            l = true;
            r = false;
        }
        if(s[i] == 'e') {
            i++;
            if(s[i] == '-' || s[i] == '+')
                i++;
            while(s[i] >= '0' && s[i] <= '9') {
                r = true;
                i++;
            }
            if(!l || !r)
                return false;
        }
        while(s[i] == ' ')
            i++;
        if(!s[i])
            return true;
        return false;
    }
};


//redo
bool isNumber(string s) {
  int l = 0, r = s.size();
  while(l < r && s[l] == ' ') l++;
  while(r > l && s[r-1] == ' ') r--;
  if(l < r && (s[l] == '+' || s[l] == '-')) l++;
  bool hasD = false;
  while(l < r && isdigit(s[l])) {
    hasD = true;
    l++;
  }
  if(l < r && s[l] == '.') {
    l++;
    while(l < r && isdigit(s[l])) {
      hasD = true;
      l++;
    }
  }
  if(!hasD) return false;
  if(l >= r) return true;
  if(s[l++] != 'e') return false;
  if(l < r && (s[l] == '+' || s[l] == '-')) l++;
  hasD = false;
  while(l < r && isdigit(s[l])) {
    hasD = true;
    l++;
  }
  return l == r && hasD;
}

