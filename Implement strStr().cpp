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


//version2
class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.size(), n = needle.size();
        if(n==0) return 0;
        int i, j;
        int next[n];
        next[0] = -1;
        i = 1, j = -1;
        while(i < n) {
            if(j == -1 || needle[i-1] == needle[j])
                next[i++] = ++j;
            else j = next[j];
        }
        
        i = 0, j = 0;
        while(i < m) {
            if(j == -1) {
                i++; j++;
            }
            else if(haystack[i] == needle[j]) {
                i++; j++;
                if(j == n) return i-j;
            }
            else j = next[j];
        }
        return -1;
    }
};