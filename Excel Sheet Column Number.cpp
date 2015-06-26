class Solution {
public:
    int titleToNumber(string s) {
        int n = 0, a = 1, b;
        for(int i = s.size()-1; i >= 0; i--) {
            b = s[i]-'A' + 1;
            n += a*b;
            a *= 26;
        }
        return n;
    }
};