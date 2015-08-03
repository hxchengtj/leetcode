class Solution {
public:
    vector<vector<bool> > b;
    int f[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    bool exist(vector<vector<char> > &board, string word) {
        b.resize(board.size());
        for(int i = 0; i < board.size(); i++)
            b[i].resize(board[i].size());
        for(int i = 0; i < board.size(); i++)
            for(int j = 0; j < board[i].size(); j++)
                if(word[0] == board[i][j]) {
                    b[i][j] = true;
                    if(dfs(board, word, 1, i, j))
                        return true;
                    b[i][j] = false;
                }
        return false;
    }
    bool dfs(vector<vector<char> > &board, string &word, int a, int x, int y) {
        if(a >= word.length())
            return true;
        int x1, y1;
        bool ret = false;
        for(int i = 0; i < 4; i++) {
            x1 = x + f[i][0];
            y1 = y + f[i][1];
            if(x1 >= 0 && x1 < board.size() && y1 >= 0 && y1 < board[0].size() && board[x1][y1] == word[a] && !b[x1][y1]) {
                b[x1][y1] = true;
                if(dfs(board, word, a+1, x1, y1))
                    return true;
                b[x1][y1] = false;
            }
        }
        return false;

    }
};

//redo
bool exist(vector<vector<char>>& board, string word) {
  if(word.size() == 0) return true;
  if(board.size() == 0 || board[0].size() == 0) return false;
  int m = board.size(), n = board[0].size();
  vector<vector<bool>> visited(m, vector<bool>(n, false));
  for(int i = 0; i < m; i++)
    for(int j = 0; j < n; j++)
      if(dfs(board, word, visited, i, j, 0))
        return true;
  return false;
}

bool dfs(vector<vector<char>>& board, string& word, vector<vector<bool>>& visited, int x, int y, int a) {
  if(a == word.size()) return true;
  if(x < 0 || x >= board.size() || y < 0 || y >= board[0].size() || visited[x][y] || board[x][y] != word[a])
    return false;
  visited[x][y] = true;
  int f[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
  for(int i = 0; i < 4; i++) {
    int k = f[i][0]+x, l = f[i][1]+y;
    if(dfs(board, word, visited, k, l, a+1))
      return true;
  }
  visited[x][y] = false;
  return false;
}

