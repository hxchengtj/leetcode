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

//redo
//version2
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0 || matrix[0].size() == 0)
            return false;
        int m = matrix.size(), n = matrix[0].size();
        int l = 0, r = m*n;
        while(l < r) {
            int mid = l + (r-l)/2;
            if(matrix[mid/n][mid%n] < target)
                l = mid+1;
            else
                r = mid;
        }
        if(l < m*n && matrix[l/n][l%n] == target)
            return true;
        return false;
    }
};