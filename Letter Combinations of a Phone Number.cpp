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
