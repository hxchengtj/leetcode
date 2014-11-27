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
