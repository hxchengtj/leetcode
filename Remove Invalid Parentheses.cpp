class Solution {
public:
    void dfs(vector<string>& ans, string& s, string& x, int i, int countl, int countr) {
        if(countl == 0 && countr == 0) {
            string a = x;
            for(int j = i; j < s.size(); j++) 
                if(s[j] != '(' && s[j] != ')') a.push_back(s[j]);
            ans.push_back(a);
            return;
        }
        int n = s.size();
        if(i == n) return;
        if(s[i] != '(' && s[i] != ')') {
            x.push_back(s[i]);
            dfs(ans, s, x, i+1, countl, countr);
            x.pop_back();
            return;
        }
        
        int tcountl = countl, t = 0, tcountr = countr, k = i, kk = i;
        while(k < n && s[k] == '(') k++;
        for(int j = i; j < n && s[j] == '(' && tcountl > 0; j++) {
            x.push_back(s[j]);
            dfs(ans, s, x, k, --tcountl, countr);
            t++;
        }
        for(int j = 0; j < t; j++) x.pop_back();
        t = 0;
        kk = k;
        k = i;
        while(k < n && s[k] == ')') k++;
        for(int j = i; j < n && s[j] == ')' && tcountr > countl; j++) {
            x.push_back(s[j]);
            dfs(ans, s, x, k, countl, --tcountr);
            t++;
        }
        for(int j = 0; j < t; j++) x.pop_back();
        dfs(ans, s, x, max(k, kk), countl, countr);
        /*
        if(s[i] == '(' && countl > 0) {
            x.push_back(s[i]);
            dfs(ans, s, x, i+1, countl-1, countr);
            x.pop_back();
        } else if(s[i] == ')' && countl < countr) { 
            x.push_back(s[i]);
            dfs(ans, s, x, i+1, countl, countr-1);
            x.pop_back();
        }
        */
    }
    vector<string> removeInvalidParentheses(string s) {
        int a = 0, n = s.size(), count = 0;
        for(char c:s) {
            if(c == '(') a++;
            else if(c == ')' && a > 0) {
                a--;
                count++;
            }
        }
        vector<string> ans;
        string x;
        dfs(ans, s, x, 0, count, count);
        return ans;
    }
};
