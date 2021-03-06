/* review again */
bool searchMatrix(vector<vector<int>>& matrix, int target) {
  if(matrix.size() == 0 || matrix[0].size() == 0) return false;
  int m = matrix.size(), n = matrix[0].size();
  int xl = 0, xr = m, yl = 0, yr = n;
  while(xl < xr && yl < yr) {
    int l = xl, r = xr;
    while(l < r) {
      int mid = l+(r-l)/2;
      if(matrix[mid][yl] == target) return true;
      else if(matrix[mid][yl] < target) l = mid+1;
      else r = mid;
    }
    xr = l;
    l = yl; r = yr;
    while(l < r) {
      int mid = l+(r-l)/2;
      if(matrix[xl][mid] == target) return true;
      else if(matrix[xl][mid] < target) l = mid+1;
      else r = mid;
    }
    yr = l;
    xl++; yl++;
  }
  return false;
}

//version2
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0 || matrix[0].size() == 0) 
            return false;
        int m = matrix.size(), n = matrix[0].size();
        int row = 0, col = n-1;
        while(row < m && col >= 0) {
            int a = matrix[row][col];
            if(a == target) return true;
            else if(a < target) row++;
            else col--;
        }
        return false;
    }
};
