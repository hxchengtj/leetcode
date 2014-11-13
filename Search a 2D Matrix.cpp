// review
class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int l = 0, r = matrix.size()-1, m, row;
        while (l <= r) {
            m = (l+r)/2;
            if(matrix[m][0] > target)
                r = m-1;
            else if(matrix[m][0] < target)
                l = m+1;
            else
                return true;
        }
        row = r;
        if(row < 0)
            return false;
        l = 0;
        r = matrix[0].size()-1;
        while(l <= r) {
            m = (l+r)/2;
            if(matrix[row][m] > target)
                r = m-1;
            else if(matrix[row][m] < target)
                l = m+1;
            else
                return true;
        }
        return false;
    }
};