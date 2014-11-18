class Solution {
public:
    void solve(vector<vector<char>> &board) {
        if(!board.size())
            return;
        int i, j, m = board.size(), n = board[0].size();
        bool b[m][n];
        int a[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        queue<pair<int, int> > q;
        for(i = 0; i < m; i++) 
            for(j = 0; j < n; j++)
                b[i][j] = false;
        for(i = 0; i < m; i++) {
            if(board[i][0] == 'O') {
                q.push(make_pair(i, 0));
                b[i][0] = true;
            }
            if(board[i][n-1] == 'O') {
                q.push(make_pair(i, n-1));
                b[i][n-1] = true;
            }
        }
        for(i = 1; i < n-1; i++) {
            if(board[0][i] == 'O') {
                q.push(make_pair(0, i));
                b[0][i] = true;
            }
            if(board[m-1][i] == 'O') {
                q.push(make_pair(m-1, i));
                b[m-1][i] = true;
            }
        }
        pair<int, int> p;
        int x, y;
        while(!q.empty()) {
            p = q.front();
            for(i = 0; i < 4; i++) {
                x = p.first + a[i][0];
                y = p.second + a[i][1];
                if(x >= 0 && x < m && y >= 0 && y < n && board[x][y] == 'O' && !b[x][y]) {
                    b[x][y] = true;
                    q.push(make_pair(x, y));
                }
            }
            q.pop();
        }
        for(i = 0; i < m; i++)
            for(j = 0; j < n; j++) 
                if(!b[i][j])
                    board[i][j] = 'X';
            
    }
};