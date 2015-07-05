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

//redo
//version2
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        int i, j, k, n = s.size();
        for(i = max(1, n-9); i <= 3 && i+3 <= n; i++) {
            if(i > 1 && s[0] == '0' || stoi(s.substr(0, i)) > 255) break;
            for(j = max(i+1, n-6); j-i <= 3 && j + 2 <= n; j++) {
                if(j > i+1 && s[i] == '0' || stoi(s.substr(i, j-i)) > 255) break;
                for(k = max(j+1, n-3); k-j <= 3 && k+1<= n; k++) {
                    if(k > j+1 && s[j] == '0' || stoi(s.substr(j, k-j)) > 255) break;
                    if(n-k > 1 && s[k] == '0' || stoi(s.substr(k, n-k)) > 255) continue;
                    ans.push_back(s.substr(0, i)+'.'+s.substr(i, j-i)+'.'+s.substr(j, k-j)+'.'+s.substr(k, n-k));
                }
            }
        }
        return ans;
    }
};
