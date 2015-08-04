class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int a = 1;
        for(int i = digits.size()-1; i >= 0; i--) {
            digits[i] += a;
            a = digits[i] / 10;
            digits[i] %= 10;
        }
        if(a)
            digits.insert(digits.begin(), a);
        return digits;
    }
};

//redo
vector<int> plusOne(vector<int>& digits) {
  vector<int> ans;
  int r = 1;
  for(int i = digits.size()-1; i >= 0; i--) {
    int a = digits[i]+r;
    ans.push_back(a%10);
    r = a/10;
  }
  if(r) ans.push_back(r);
  reverse(ans.begin(), ans.end());
  return ans;
}

