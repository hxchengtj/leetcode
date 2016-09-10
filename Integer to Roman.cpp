/* review again */
class Solution {
public:
    int a[7] = {1000, 500, 100, 50, 10, 5, 1};
    char c[7] = {'M', 'D', 'C', 'L', 'X', 'V', 'I'};
    string intToRoman(int num) {
        string s;
        int x;
        for(int i = 0; i < 7; i++) {
            x = num/a[i];
            num = num%a[i];
            if(x <= 3)
                s.insert(s.end(), x, c[i]);
            else if(s.size() == 0 || s.back() != c[i-1]){
                s += c[i];
                s += c[i-1];
            }
            else {
                s.pop_back();
                s += c[i];
                s += c[i-2];
            }
        }
        return s;
    }
};

//version2
string intToRoman(int num) {
  string r[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
  int a[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
  string ans;
  int i = 0;
  while(num) {
    if(num >= a[i]) {
      num -= a[i];
      ans.append(r[i]);
    }
    else i++;
  }
  return ans;
}


