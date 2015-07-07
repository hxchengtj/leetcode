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

//redo
//version2
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        char m[256];
        
        memset(m, 0, sizeof(m));
        bitset<256> b;
        for(size_t i = 0; i < s.size(); i++) {
            if(m[s[i]]) {
                if(m[s[i]] != t[i]) return false;
            }
            else if(b[t[i]]) return false;
            else {
                m[s[i]] = t[i];
                b[t[i]] = true;
            }
        }
        return true;
    }
};
