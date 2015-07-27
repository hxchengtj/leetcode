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

// redo
// version2
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> v[n+1];
        v[0].push_back("");
        for(int i = 1; i <= n; i++)
            for(int j = 0; j < i; j++) {
                vector<string> &a = v[j];
                vector<string> &b = v[i-j-1];
                for(string &v1:a)
                    for(string &v2:b) {
                        string s = v1 + '(' + v2 + ')';
                        v[i].push_back(s);
                    }
            }
        return v[n];
    }
};


//version3
vector<string> ans;
string s;
vector<string> generateParentheses(int n) {
  ans.clear();
  s = "";
  dfs(n, 0);
  return ans;
}
void dfs(int n, int nr) {
  if(n == 0) {
    s.append(nr, ')');
    ans.push_back(s);
    s.resize(s.size()-nr);
    return;
  }

  s.push_back('(');
  dfs(n-1, nr+1);
  if(nr > 0) {
    s.back() = ')';
    dfs(n, nr-1);
  }
  s.pop_back();
}

