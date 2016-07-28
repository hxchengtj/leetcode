// without test
class Solution {
public:
  int depthSum(vector<NestedInteger>& nestedList) {
    return dfs(nestedList, 1);
  }
  int dfs(vector<NestedInteger>& nestedList, int d) {
    int ans = 0;
    for(auto &a: nestedList) 
      ans += a.isInteger() ? a.getInteger() * d : dfs(a.getList(), d+1);
    return ans;
  }
};
