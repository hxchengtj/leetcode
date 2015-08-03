class Solution {
public:
    int romanToInt(string s) {
        int t[26] = {0, 0, 100, 500, 0, 0, 0, 0, 1, 0, 0, 50, 1000, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 10, 0, 0};
        int ans = 0, i, j, k;
        for(i = 0; i < s.length() - 1; i++) {
            j = s[i] - 'A';
            k = s[i+1] - 'A';
            if(t[j] < t[k])
                ans -= t[j];
            else
                ans += t[j];
        }
        j = s[i] - 'A';
        ans += t[j];
        return ans;
    }
};

//redo
int romanToInt(string s) {
  int roman[26];
  roman['I'-'A'] = 1;
  roman['V'-'A'] = 5;
  roman['X'-'A'] = 10;
  roman['L'-'A'] = 50;
  roman['C'-'A'] = 100;
  roman['D'-'A'] = 500;
  roman['M'-'A'] = 1000;
  if(s.size() == 0) return 0;
  int ans = roman[s[0]-'A'];
  for(int i = 1;i < s.size(); i++) {
    ans += roman[s[i]-'A'];
    if(roman[s[i-1]-'A'] < roman[s[i]-'A']) ans -= 2*roman[s[i-1]-'A'];
  }
  return ans;
}

