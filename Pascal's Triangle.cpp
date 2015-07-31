class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > ans;
        vector<int> v;
        int i, j, k;
        for(i = 1; i <= numRows; i++) {
            k = 1;
            for(j = 1; j < i - 1; j++) {
                v[j] = v[j]+k;
                k = v[j]-k;
            }
            v.push_back(1);
            ans.push_back(v);
        }
        return ans;
    }
};

//redo
vector<vector<int>> generate(int numRows) {
  vector<vector<int>> ans;
  vector<int> v;
  if(numRows <= 0) return ans;
  for(int i = 0; i < numRows; i++) {
    ans.push_back(vector<int>(i+1, 1));
    for(int j = 1; j < i; j++)
      ans[i][j] = ans[i-1][j-1]+ans[i-1][j];
  }
  return ans;
}

