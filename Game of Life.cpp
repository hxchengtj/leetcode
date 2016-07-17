class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        if(board.size() == 0 || board[0].size() == 0) return;
        int m = board.size(), n = board[0].size();
        int f[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++) {
                int count = 0;
                for(int k = 0; k < 8; k++) {
                    int ii = i+f[k][0], jj = j+f[k][1];
                    if(ii >= 0 && ii < m && jj >=0 && jj < n && board[ii][jj] > 0) count++;
                }
                if(board[i][j] == 1 && (count < 2 || count > 3)) board[i][j] = 2;
                else if(board[i][j] == 0 && count == 3) board[i][j] = -1;
            }
       for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++) {
                if(board[i][j] == 2) board[i][j] = 0;
                else if(board[i][j] == -1) board[i][j] = 1;
            }     
    }
};
