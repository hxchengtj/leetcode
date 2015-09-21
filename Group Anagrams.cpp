vector<vector<string>> groupAnagrams(vector<string>& strs) {
  unordered_map<string, vector<string>> m;
  for(auto &s:strs) {
    string t = s;
    sort(t.begin(), t.end());
    m[t].push_back(s);
  }
  vector<vector<string>> ans;
  for(auto &p:m) {
    sort(p.second.begin(), p.second.end());
    ans.push_back(p.second);
  }
  return ans;
}

