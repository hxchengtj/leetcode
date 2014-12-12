class Solution {
public:
    int strStr(char *haystack, char *needle) {
        int i = 0, k = -1, n = strlen(haystack), m = strlen(needle);
        if(m == 0)
            return 0;
        vector<int> next(m+n+1);
        string s;
        s = needle;
        s += haystack;
        next[0] = -1;
        while(i < s.length()) {
            if(k == -1 || s[k] == s[i]) {
                next[++i] = ++k;
                if(i == m) k = 0;
                if(k == m) return i-m*2;
            }
            else k = next[k];
        }
        return -1;
    }
};