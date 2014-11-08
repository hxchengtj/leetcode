class Solution {
public:
    int ans;
    vector<bool> column, ldiagonal, rdiagonal;
    int totalNQueens(int n) {
        ans = 0;
        column.resize(n);
        ldiagonal.resize(2*n);
        rdiagonal.resize(2*n);
        dfs(0, n);
        return ans;
    }
    void dfs(int row, int n) {
        if(row == n) {
            ans++;
            return;
        }
        int i;
        for(i = 0; i < n; i++)
            if(!column[i] && !ldiagonal[i-row+n-1] && !rdiagonal[i+row]) {
                column[i] = true;
                ldiagonal[i-row+n-1] = true;
                rdiagonal[i+row] = true;
                dfs(row+1, n);
                column[i] = false;
                ldiagonal[i-row+n-1] = false;
                rdiagonal[i+row] = false;                
            }
    }
};
