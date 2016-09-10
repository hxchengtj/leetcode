/* review again */
int myAtoi(string str) {
  int n = str.size();
  int l = 0, r = n-1;
  while(l < n && str[l] == ' ') l++;
  while(r >= l && str[r] == ' ') r--;
  if(l > r) return 0;
  bool isNeg = false;
  if(!isdigit(str[l])) {
    if(str[l] == '-') isNeg = true;
    else if(str[l] != '+') return 0;
    l++;
  }
  int ans = 0;
  for(int i = l; i <= r && isdigit(str[i]); i++) {
    if(ans >= (INT_MIN+(str[i]-'0'))/10) ans = ans*10 -(str[i]-'0');
    else return isNeg? INT_MIN:INT_MAX;
  }
  if(ans == INT_MIN && !isNeg) return INT_MAX;
  return isNeg? ans:-ans;
}

//redo 
class Solution {
public:
    int myAtoi(string str) {
        bool isNeg = false;
        int ans = 0, i = 0, n = str.size();
        while(i < n && str[i] == ' ') i++;
        if(str[i] == '+' || str[i] == '-') {
            if(str[i] == '-') isNeg = true;
            i++;
        } 
        for(; i < n && str[i] >= '0' && str[i] <= '9'; i++) {
            if(ans >= (INT_MIN + (str[i]-'0')) / 10) ans = 10*ans-(str[i]-'0');
            else {
                ans = INT_MIN; break;
            }
        }
        return isNeg? ans: (ans == INT_MIN?INT_MAX:-ans);
    }
};
