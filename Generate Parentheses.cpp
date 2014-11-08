// review
// 计算个数动规：f[n] = sum(f[i] * f[n-i-1])
class Solution {
public:
    string s;
    vector<string> v;
    char c[2] = {'(', ')'};
    int a[2][2] = {{1, 0}, {0, 1}};
    vector<string> generateParenthesis(int n) {
        v.clear();
        s = "";
        dfs(0, 0, n);
        return v;
    }
    void dfs(int x, int y, int n) {
        if(x == n) {
            for(int i = y; i < n; i++)
                s += ')';
            v.push_back(s);
            for(int i = y; i < n; i++)
                s.erase(s.end()-1);
            return;
        }
        if(x == y) {
            s = s + '(';
            dfs(x+1, y, n);
            s.erase(s.end()-1);
        }
        else if(x > y) {
            for(int i = 0; i < 2; i++) {
                s = s + c[i];
                dfs(x + a[i][0], y + a[i][1], n);
                s.erase(s.end()-1);
            }
        }
    }
};
