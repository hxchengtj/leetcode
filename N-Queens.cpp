class Solution {
public:
    vector<vector<string>> s;
    vector<string> v;
    vector<bool> column, ldiagonal, rdiagonal;
    vector<vector<string> > solveNQueens(int n) {
        column.resize(n);
        ldiagonal.resize(2*n);
        rdiagonal.resize(2*n);
        dfs(0, n);
        return s;
    }
    void dfs(int row, int n) {
        if(row == n) {
            s.push_back(v);
            return;
        }
        int i;
        string t(n, '.');
        for(i = 0; i < n; i++) {
            if(!column[i] && !ldiagonal[i-row+n-1] && !rdiagonal[i+row]) {
                column[i]  = true;
                ldiagonal[i-row+n-1] = true;
                rdiagonal[i+row] = true;
                t[i] = 'Q';
                v.push_back(t);
                dfs(row+1, n);
                v.erase(v.end()-1);
                t[i] = '.';
                column[i]  = false;
                ldiagonal[i-row+n-1] = false;
                rdiagonal[i+row] = false;
            }
        }
    }
};

//redo
vector<vector<string>> ans;
vector<string> v;
vector<bool> column, ldiagonal, rdiagonal;
vector<vector<string>> solveNQueens(int n) {
  ans.clear(); v.clear(); column.clear(); ldiagonal.clear(); rdiagonal.clear();
  column.resize(n); ldiagonal.resize(2*n); rdiagonal.resize(2*n);
  dfs(0, n);
  return ans;
}

void dfs(int row, int n) {
  if(row == n) {
    ans.push_back(v);
    return;
  }
  string s(n, '.');
  int j = row;
  for(int i = 0; i < n; i++) {
    if(!column[i] && !ldiagonal[i-j+n-1] && !rdiagonal[i+j]) {
      column[i] = ldiagonal[i-j+n-1] = rdiagonal[i+j] = true;
      s[i] = 'Q';
      v.push_back(s);
      dfs(row+1, n);
      v.pop_back();
      s[i] = '.';
      column[i] = ldiagonal[i-j+n-1] = rdiagonal[i+j] = false;
    }
  }
}

