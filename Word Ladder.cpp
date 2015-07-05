// review
class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        int n = (*dict.begin()).size(), i, j, k;
        queue<string> q;
        unordered_map<string, int> map;
        for(unordered_set<string>::iterator iter = dict.begin(); iter != dict.end(); iter++)    //****************
            map[*iter] = 0;
        string s;
        char c, t;
        map[start] = 1;
        q.push(start);
        while(!q.empty()) {
            s = q.front();
            k = map[s];
            if(s == end)
                return k;
            if(mycompare(s, end))
                return k+1;
            for(i = 0; i < n; i++)
                for(j = 0; j < 26; j++) {
                    c = 'a' + j;
                    if(c != s[i]) {
                        t = s[i];
                        s[i] = c;
                        if(map.find(s) != map.end() && map[s] == 0) {                   //***************
                            map[s] = k+1;
                            q.push(s);
                        }
                        s[i] = t;
                    }
                }
            q.pop();
        }
        return 0;
    }
    bool mycompare(string &x, string &y) {
        bool b = false;
        for(int i = 0; i < x.length(); i++) {
            if(x[i] != y[i]) {
                if(b)
                    return false;
                b = true;
            }
        }
        return b;
    }
};

//redo
class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordDict) {
        unordered_map<string, int> m;
        queue<string> q;
        m[beginWord] = 1;
        q.push(beginWord);
        while(!q.empty()) {
            string w = q.front();
            q.pop();
            if(w == endWord) return m[w];
            int l = m[w];
            for(int i = 0; i < w.size(); i++) {
                char co = w[i];
                for(char c = 'a'; c <= 'z'; c++) {
                    w[i] = c;
                    if(wordDict.find(w) != wordDict.end() && m.find(w) == m.end()) {
                        m[w] = l+1;
                        q.push(w);
                    }
                }
                w[i] = co;
            }
        }
        return 0;
    }
};