// without test
class Solution {
public:
  int depthSumInverse(vector<NestedInteger>& nestedList) {  
    int d = dfs(nestedList, ans);
    return getSum(nestedList, d);
  }
  int dfs(vector<NestedInteger>& nestedList) {
    int d = 1;
    for(auto &a: nestedList) 
      if(!a.isInteger()) d = max(d, dfs(a.getList())+1);
    return d;
  }
  int getSum(vector<NestedInteger>& nestedList, int d) {
    int sum = 0;
    for(auto &a: nestedList) 
      sum += a.isInteger()?a.getInteger()*d:getSum(a.getList(), d-1);
    return sum;
  }
};
