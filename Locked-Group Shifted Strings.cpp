class Solution {
public:
  vector<vector<string>> groupStrings(vector<string>& strings) {
    unordered_map<string, vector<string>> m;
    for(string &s:strings) {
      string a="";
      for(int i = 1; i < s.size(); i++) 
        a += to_string((s[i]-s[i-1]+26)%26) + " ";
      m[a].push_back(s);
    } 
    vector<vector<string>> ans;
    for(auto p:m) {
      auto v = p.second;
      sort(v.begin(), v.end());
      ans.push_back(v);
    }
    return ans;
  }
};
