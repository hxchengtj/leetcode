class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> p;
        p.push_back(1);
        int f;
        for(int i = 1; i <= rowIndex; i++) {
            f = 1;
            for(int j = 1; j < i; j++) {
                p[j] = p[j]+f;
                f = p[j]-f;
            }
            p.push_back(1);
        }
        return p;
    }
};

//redo
vector<int> getRow(int rowIndex) {
  vector<int> ans(rowIndex+1);
  ans[0] = 1;
  for(int i = 1; i <= rowIndex; i++) {
    ans[i] = 1;
    for(int j = i-1; j > 0; j--) ans[j] += ans[j-1];
  }
  return ans;
}

