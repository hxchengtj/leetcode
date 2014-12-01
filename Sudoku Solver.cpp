class Solution {
public:
    bool row[9][9], column[9][9], block[9][9];
    void solveSudoku(vector<vector<char> > &board) {
        int  t;
        for(int i = 0; i < 9; i++)
            for(int j = 0; j < 9; j++)
                row[i][j] = column[i][j] = block[i][j] = false;
        for(int i = 0; i < 9; i++)
            for(int j = 0; j < 9; j++) {
                t = board[i][j] - '1';
                if(board[i][j] != '.')
                    row[i][t] = column[j][t] = block[(i/3)*3+j/3][t] = true;
        }
        dfs(0, 0, board);
    }
    bool dfs(int a, int b, vector<vector<char> > &board) {
        for(int x = a; x < 9; x++)
            for(int y = 0; y < 9; y++) {                //注意起始位置@@
                if(x == a)
                    y = max(y, b);
                if(board[x][y] == '.') {
                    for(int i = 0; i < 9; i++)
                        if(!row[x][i] && !column[y][i] && !block[(x/3)*3+y/3][i]) {
                            board[x][y] = i+'1';
                            row[x][i] = column[y][i] = block[(x/3)*3+y/3][i] = true;
                            if(dfs(x, y, board))
                                return true;
                            board[x][y] = '.';
                            row[x][i] = column[y][i] = block[(x/3)*3+y/3][i] = false;  
                        }
                    return false;
                }
            }
        return true;
    }
};
