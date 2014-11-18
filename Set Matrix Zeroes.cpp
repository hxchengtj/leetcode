class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        int i, j;
        bool row = false, column = false;
        for(i = 0; i < matrix.size(); i++)
            for(j = 0; j < matrix[i].size(); j++) 
                if(matrix[i][j] == 0) {
                    row = row || (i == 0);
                    column = column || (j == 0);
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
        for(i = 1; i < matrix.size(); i++)
            for(j = 1; j < matrix[i].size(); j++) {
                if(!matrix[i][0] || !matrix[0][j])
                    matrix[i][j] = 0;
            }
        if(row) {
            for(i = 0; i < matrix[0].size(); i++)
                matrix[0][i] = 0;
        }
        if(column) {
            for(i = 0; i < matrix.size(); i++)
                matrix[i][0] = 0;
        }
    }
};