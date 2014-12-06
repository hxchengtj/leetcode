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