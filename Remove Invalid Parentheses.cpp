/* review again */
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

//version2
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        int n = s.size();
        vector<string> ans;
        removeP(ans, s, 0, 0, {'(', ')'});
        return ans;
    }
    //每次删掉一个同时避免重复,先去掉多余的')'
    void removeP(vector<string>& ans, string s, int last_i, int last_j, pair<int, int> p) {
        int cnt = 0;
        for(int i = last_i; i < s.size(); i++) {
            if(s[i] == p.first) cnt++;
            else if(s[i] == p.second) cnt--;
            if(cnt < 0) {
                for(int j = last_j; j <= i; j++) {
                    if(s[j] == p.second && (j == last_j || s[j-1] != s[j]))
                        removeP(ans, s.substr(0, j)+s.substr(j+1), i, j, p);
                }
                return;
            }
        }
        //reverse后去掉多余的'('
        reverse(s.begin(), s.end());
        if(p.first == '(')
            removeP(ans, s, 0, 0, {')', '('});
        else 
            ans.push_back(s);
        
    }
};
