class Solution {
public:
  int minArea(vector<vector<char>>& image, int x, int y) {
    if(image.size() == 0 || image[0].size() == 0) return 0;
    int m = image.size(), n = image[0].size();
    int l = find_row(0, x, image, true);
    int r = find_row(x, n-1, image, false);
    int u = find_col(0, y, image, true);
    int d = find_col(y, m-1, image, false);
    return (r-l)*(d-u);
  }
  int find_row(int l, int r, vector<vector<char>>& image, bool isLowerBound) {
    while(l <= r) {
      int m = l+(r-l)/2;
      bool hasBlack = false;
      for(int i = 0; i < image.size() && !hasBlack; i++) hasBlack = image[i][m] == '1';
      if(hasBlack == isLowerBound) r = m-1;
      else l = m+1;
    }
    return r;
  }
  int find_col(int l, int r, vector<vector<char>>& image, bool isLowerBound) {
    while(l <= r) {
      int m = l+(r-l)/2;
      bool hasBlack = false;
      for(int i = 0; i < image[0].size() && !hasBlack; i++) hasBlack = image[m][i] == '1';
      if(hasBlack == isLowerBound) r = m-1;
      else l = m+1;
    }
    return r;
  }
};
