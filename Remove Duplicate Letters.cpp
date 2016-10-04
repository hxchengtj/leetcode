/* review again */
//redo
class Solution {
public:
    string removeDuplicateLetters(string s) {
        if(s.size() == 0) return "";
        vector<int> cnt(26);
        for(char c:s) cnt[c-'a']++;
        int pos = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[pos] > s[i]) pos = i;
            if(--cnt[s[i]-'a'] == 0) break;
        }
        string str;
        for(int i = pos+1; i < s.size(); i++) if(s[i] != s[pos]) str.push_back(s[i]);
        return s[pos]+removeDuplicateLetters(str);
    }
};
