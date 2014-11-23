// review
/*
class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        int i, j, n = matrix.size(), t;
        for(i = 0; i <= (n-1)/2; i++)
            for(j = 0; j < n/2; j++) {                      //奇数边界
                t = matrix[i][j];
                matrix[i][j] = matrix[n-1-j][i];
                matrix[n-1-j][i] = matrix[n-1-i][n-1-j];
                matrix[n-1-i][n-1-j] = matrix[j][n-1-i];
                matrix[j][n-1-i] = t;
            }
    }
};
*/

class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        int i, j, n = matrix.size(), t;
        for(i = 0; i < n; i++)
            for(j = 0; j < i; j++)   
                swap(matrix[i][j], matrix[j][i]);
        for(i = 0; i < n; i++)
            for(j = 0; j < n/2; j++)
                swap(matrix[i][j], matrix[i][n-1-j]);
    }
};