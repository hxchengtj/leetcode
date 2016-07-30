//redo 
class Solution {
public:
  string rearrangeString(string str, int k) {
    string s;
    int n = str.size();
    priority_queue<pair<int, char>> q;
    unordered_map<char, int> m;
    for(auto & c:str) m[c]++;
    for(auto &p:m) q.push({p.second, p.first});
    while(!q.empty()) {
      int l = min(n, k);
      if(q.size() < l) return "";
      vector<pair<int, char>> cache;
      for(int i = 0; i < l; i++) {
        auto t = q.top();
        q.pop();
        s.push_back(t.second);
        if(--t.first > 0) cache.push_back({t.first, t.second});
        n--;
      }
      for(auto &p:cache) q.push(p);
    }
    return s;
  }
};
