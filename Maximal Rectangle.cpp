#include <iostream>
#include <vector>
using namespace std;
//hard
class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return 0;
        int i, j, k;
        int tmpv, tmpb, tmpa;
        int max_area = 0;
        vector<int> height(matrix[0].size());
        vector<int> value(matrix[0].size()), begin(matrix[0].size());
        for(i = 0;i < matrix.size(); i++) {
            if (i == 0) {
                for(j = 0;j < matrix[i].size(); j++)
                    height[j] = matrix[i][j] - '0';
            }
            else {
                for(j = 0;j < matrix[i].size(); j++)
                    if(matrix[i][j] == '1')
                        height[j]++;
                    else
                        height[j] = 0;
            }
            value[0] = height[0];
            begin[0] = 0;
            for(j = 1;j < height.size(); j++) {
                if(height[j] == height[j-1]) {
                    value[j] = height[j];
                    begin[j] = begin[j-1];
                }
                else if (height[j] > height[j-1]) {
                    value[j] = height[j];
                    begin[j] = j;
                }
                else {
                    value[j] = height[j];
                    k = j-1;
                    while(k >= 0 && value[k] > height[j]) {
                       tmpv = value[k];
                       tmpb = begin[k];
                       tmpa = (j-tmpb) * tmpv;
                       if(tmpa > max_area)
                           max_area = tmpa;
                       k = begin[k]-1;
                    }
                    if(k < 0)
                        begin[j] = 0;
                    else if (value[k] == height[j])
                        begin[j] = begin[k];
                    else
                        begin[j] = k+1;
                }
            }
            k = j-1;
            while(k >= 0) {
                tmpv = value[k];
                tmpb = begin[k];
                tmpa = (j-tmpb) * tmpv;
                if(tmpa > max_area)
                    max_area = tmpa;
                k = begin[k] - 1;
            }

        }
        return max_area;
    }

};
int main() {

    return 0;
}

//redo
int __maximalRectangle(vector<int>& sum) {
  int n = sum.size();
  stack<int> stk;
  int left[n];
  for(int i = 0; i < n; i++) {
    while(!stk.empty() && sum[stk.top()] >= sum[i]) stk.pop();
    left[i] = stk.empty()? 0:stk.top()+1;
    stk.push(i);
  }
  stk = stack<int>();
  int ans = 0, right;
  for(int i = n-1; i >= 0; i--) {
    while(!stk.empty() && sum[stk.top()] >= sum[i]) stk.pop();
    right = stk.empty()? n:stk.top();
    ans = max(ans, (right-left[i])*sum[i]);
    stk.push(i);
  }
  return ans;
}
int maximalRectangle(vector<vector<char>>& matrix) {
  if(matrix.size() == 0 || matrix[0].size() == 0) return 0;
  int m = matrix.size(), n = matrix[0].size();
  int ans = 0;
  vector<int> sum(n, 0);
  for(int i = 0; i < m; i++) {
    for(int j = 0; j < n; j++) {
      if(matrix[i][j] == '1') sum[j] += 1;
      else sum[j] = 0;
    }
    ans = max(ans, __maximalRectangle(sum));
  }
  return ans;
}

