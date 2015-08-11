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

//redo
void dfs(vector<vector<char>>& board, int x, int y) {
  queue<pair<int, int>> q;
  if(board[x][y] == 'O') {
    q.push(make_pair(x, y));
    board[x][y] = 'A';
    while(!q.empty()) {
      pair<int, int> p = q.front();
      q.pop();
      int f[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
      for(int i = 0; i < 4; i++) {
        int x1 = p.first+f[i][0], y1 = p.second+f[i][1];
        if(x1 >= 0 && x1 < board.size() && y1 >= 0 && y1 < board[0].size() && board[x1][y1] == 'O') {
          board[x1][y1] = 'A';
          q.push(make_pair(x1, y1));
        }
      }
    }
  }
}

void solve(vector<vector<char>>& board) {
  if(board.size() == 0 || board[0].size() == 0) return;
  int m = board.size(), n = board[0].size();
  for(int i = 0; i < m; i++) {
    dfs(board, i, 0);
    dfs(board, i, n-1);
  }
  for(int i = 0; i < n; i++) {
    dfs(board, 0, i);
    dfs(board, m-1, i);
  }
  for(int i = 0; i < m; i++)
    for(int j = 0; j < n; j++)
      if(board[i][j] == 'O') board[i][j] = 'X';
      else if(board[i][j] == 'A') board[i][j] = 'O';
}



