class TicTacToe {
public:
  TicTacToe(int n){
    rows.resize(n);
    cols.resize(n);
    dia = anti_dia = 0;
    this->n = n;
  }
    
  int move(int row, int col, int player) {
    int p = player == 1?1:-1;
    rows[row] += p; cols[col] += p;
    if(row == col) dia += p;
    if(row+col == n-1) anti_dia += p;
    if (rows[row] == p*n || cols[col] == p*n || dia == p*n || anti_dia == p*n)
      return player;
    else return 0;
  }

private:
  vector<int> rows;
  vector<int> cols;
  int dia, anti_dia, n;
};

