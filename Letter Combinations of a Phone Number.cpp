class Solution {
public:
    char c[10][5] = {" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    string s;
    vector<string> ans;
    vector<string> letterCombinations(string digits) {
        dfs(0, digits);
        return ans;
    }
    void dfs(int a, string &digits) {
        if(a >= digits.length()) {
            ans.push_back(s);
            return;
        }
        int i, j = digits[a]-'0';
        for(i = 0; i < 5 && c[j][i] != 0; i++) {
            s += c[j][i];
            dfs(a+1, digits);
            s.pop_back();
        }
    }
};

//redo
vector<string> ans;
string s;
const string phone[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
void dfs(string& digits, int l) {
  if(l == digits.size()) {
    ans.push_back(s);
    return;
  }
  string a = phone[digits[l]-'0'];
  if(a.size() == 0) dfs(digits, l+1);
  else {
    for(char c:a) {
      s.push_back(c);
      dfs(digits, l+1);
      s.pop_back();
    }
  }
}
vector<string> letterCombinations(string digits) {
  ans.clear();
  s.clear();
  if(digits.empty()) return ans;
  dfs(digits, 0);
  return ans;
}

