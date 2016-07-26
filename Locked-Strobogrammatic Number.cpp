class Solution {
public:
  bool isStrobogrammatic(string num) {
    char f[10] = {'0', '1', 'a', 'a', 'a', 'a', '9', 'a', '8', '6'};
    int i = 0, j = num.size()-1;
    while(i <= j) {
      if(f[num[i]-'0'] != num[j]) return false;
      i++; j--;
    }
    return true;
  }
};
