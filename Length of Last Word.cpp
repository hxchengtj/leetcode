class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int n = strlen(s), i = n-1, j = 0;
        while(s[i] == ' ')
            i--;
        for(; s[i] != 0 && s[i] != ' '; i--)
            j++;
        return j;
    }
};
