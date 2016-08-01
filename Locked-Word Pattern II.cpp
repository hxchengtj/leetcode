class Solution {
public:
  bool wordPatternMatch(string pattern, string str) {
    unordered_map<char, string> m;
    unordered_set<string> s;
    return dfs(pattern, str, 0, 0, m, s);
  }
  bool dfs(string& pattern, string& str, int i, int j, unordered_map<char, string>& m, unordered_set<string>& s) {
    if(i == pattern.size() && j == str.size()) return true;
    if(i == pattern.size() || j == str.size()) return false;
    char p = pattern[i];
    if(m.find(p) != m.end()) {
      string w = m[p];
      for(int k = 0; k < w.size(); k++) 
        if(w[k] != str[j+k]) return false;
      return dfs(pattern, str, i+1, j+w.size(), m, s);
    }
    for(int k = 1; k < str.size()-j; k++) {
      string w = str.substr(j, k);
      if(s.find(w) != s.end()) continue;
      m[p] = w;
      s.insert(w);
      if(dfs(pattern, str, i+1, j+k, m, s)) return true;
      s.erase(w);
      m.erase(p);
    }
    return false;
  }
};
