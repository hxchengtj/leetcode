class Solution {
public:
    char findTheDifference(string s, string t) {
        int dict[26];
        memset(dict, 0, sizeof(dict));
        for(char c:s) dict[c-'a']++;
        for(char c:t) dict[c-'a']--;
        for(int i = 0; i < 26; i++)
            if(dict[i] == -1) return i+'a';
        return '\0';
    }
};
