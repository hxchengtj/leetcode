// review
class Solution {
public:
    vector<string> ans;
    string a;
    vector<string> restoreIpAddresses(string s) {
        dfs(4, s, 0);
        return ans;
    }
    void dfs(int x, string &s, int y) {
        int i, j, n = s.length(), t = 0;
        if(y >= n)
            return;
        if(x == 1) {
            if(s[y] == '0' && y != n-1 || (n-y) > 3)
                return;
            for(i = y; i < n; i++) {
                t = t*10 + s[i] - '0';
            }
            if(y < n && t <= 255)
                ans.push_back(a+'.'+to_string(t));
            return;
        }
        t = 0;    
        if(x != 4)
            a += '.';
        if(s[y] == '0') {
            a += '0';
            dfs(x-1, s, y+1);
            a.pop_back();
            if(x != 4)
                a.pop_back();
            return;
        }
        for(i = y; i < y + 3 && i < n; i++) {
            t = t*10 + s[i] - '0';
            a += s[i];
            if(t <= 255) 
                dfs(x-1, s, i+1);
        }
        for(i = y; i < y + 3 && i < n; i++) 
            a.pop_back();
        if(x != 4)
            a.pop_back();
    }
};