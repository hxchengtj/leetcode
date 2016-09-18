/* review again */
class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        vector<int> sum(triangle.size()+1);
        int i, j;
        for(i = triangle.size()-1; i >= 0; i--)
            for(j = 0;j < triangle[i].size();j++)
                sum[j] = min(sum[j], sum[j+1]) + triangle[i][j];
        return sum[0];
    }
};


//redo
int minimumTotal(vector<vector<int>>& triangle) {
  if(triangle.size() == 0) return 0;
  int m = triangle.back().size(), n = triangle.size();
  vector<int> f(triangle.back());
  for(int i = n-2; i >= 0; i--)
    for(int j = 0; j <= i; j++)
      f[j] = min(f[j], f[j+1]) + triangle[i][j];
  return f[0];
}

