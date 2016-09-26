/* review again */
vector<int> dfs(vector<int>& vals, vector<char>& ops, int l, int r) {
  if(l == r) return {vals[l]};
  vector<int> ans;
  for(int i = l; i < r; i++) {
    vector<int> vl = dfs(vals, ops, l, i);
    vector<int> vr = dfs(vals, ops, i+1, r);
    for(auto numl:vl)
      for(auto numr:vr) {
        switch(ops[i]) {
          case '+': ans.push_back(numl+numr); break;
          case '-': ans.push_back(numl-numr); break;
          case '*': ans.push_back(numl*numr);
        }
      }
  }
  return ans;
}
vector<int> diffWaysToCompute(string input) {
  vector<int> vals;
  vector<char> ops;
  int n = input.size(), i = 0;
  while(i < n) {
    if(isdigit(input[i])) {
      int j = i;
      while(j < n && isdigit(input[j])) j++;
      vals.push_back(stoi(input.substr(i, j-i)));
      i = j;
    }
    else ops.push_back(input[i++]);
  }
  if(vals.empty()) return {};
  return dfs(vals, ops, 0, ops.size());
}

