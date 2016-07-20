class NumMatrix {
public:
    vector<vector<int>> sum;
    NumMatrix(vector<vector<int>> &matrix) {
        sum.clear();
        if(matrix.size() == 0 || matrix[0].size() == 0) return;
        
        int m = matrix.size(), n = matrix[0].size();
        sum.resize(m+1, vector<int>(n+1));
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                sum[i+1][j+1] += sum[i][j+1]+sum[i+1][j]-sum[i][j]+matrix[i][j];
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return sum[row2+1][col2+1]-sum[row1][col2+1]-sum[row2+1][col1]+sum[row1][col1];
    }
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);