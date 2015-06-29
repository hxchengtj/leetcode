class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> m;
        unordered_set<char> c;
        int n = s.size();
        for(int i = 0; i < n; i++) {
            if(m.find(s[i]) != m.end()) {
                if(m[s[i]] != t[i])
                    return false;
            }
            else {
                if(c.find(t[i]) != c.end())
                    return false;
                m.insert(make_pair(s[i], t[i]));
                c.insert(t[i]);
            }
        }
        return true;
    }
};