class Solution {
public:
    bool wordPattern(string pattern, string str) {
        vector<string> dict(26);
        unordered_map<string, char> m;
        int i = 0, n = str.size();
        for(char c:pattern) {
            while(i < n && str[i] == ' ') i++;
            int j = i;
            while(i < n && str[i] != ' ') i++;
            if(j == i) return false;
            string s = str.substr(j, i-j);
            // 一一对应关系
            if(dict[c-'a'].size() > 0 && dict[c-'a'] != s ) return false;
            if(m.find(s) != m.end() && m[s] != c) return false;
            dict[c-'a'] = s;
            m[s] = c;
        }
        while(i < n && str[i] == ' ') i++;
        return i == n;
    }
};
