class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        int i, j, k;
        bool row[9][9], column[9][9], block[9][9];
        for(i = 0; i < 9;++i)
            for (j = 0;j < 9;++j) {
                row[i][j] = false;
                column[i][j] = false;
                block[i][j] = false;
            }
        for (i = 0;i < 9;++i)
            for (j = 0;j < 9;++j)
                if(board[i][j] != '.') {
                    k = board[i][j]-'1';
                    if (row[i][k] || column[j][k] || block[(i/3)*3+j/3][k])
                        return false;
                    row[i][k] = true;
                    column[j][k] = true;
                    block[(i/3)*3+j/3][k] = true;
                }
        return true;
    }
};