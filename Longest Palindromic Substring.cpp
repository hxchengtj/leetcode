class Solution {
public:
    string longestPalindrome(string s) {
        string ans = s.substr(0, 1), t;
        int n = s.size();
        for(int i = 0; i < n-1; i++) {
            t = centerpalindrome(s, i, i);
            if(t.size() > ans.size())
                ans = t;
            t = centerpalindrome(s, i, i+1);
            if(t.size() > ans.size())
                ans = t;
        }
        return ans;
    }
    string centerpalindrome(string &s, int a, int b) {
        int l, r;
        for(l = a, r = b; l >= 0 && r < s.length() && s[l] == s[r]; l--, r++);
        l++;
        return s.substr(l, r-l);
    }
};