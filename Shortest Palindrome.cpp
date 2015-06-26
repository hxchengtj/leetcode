class Solution {
public:
    string shortestPalindrome(string s) {
        string a = s, b;
        reverse(a.begin(), a.end());
        for(int i = s.size(); i > 0; i--) {
            if(s.substr(0, i) == a.substr(a.size()-i, i)) {
                b = a.substr(0, a.size()-i) + s;
                return b;
            }
        }
        return b;
    }
};