class Solution {
public:
  vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
    int m = A.size(), n = A[0].size(), p = B[1].size();
    vector<vector<int>> C(m, vector<int>(p));
    for(int i = 0; i < m; i++)
      for(int j = 0; j < n; j++)
        if(A[i][j]) {
          for(int k = 0; k < p; k++)
            C[i][k] += A[i][j]*B[j][k];
        }
    return C;
  }
};
