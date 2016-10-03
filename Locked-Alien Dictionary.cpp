/* review again */
class Solution {
public:
  string alienOrder(vector<string>& words) {
    unordered_map<char, vector<char>> m;
    unordered_map<char, int> cnt;
    for(int i = 1; i < words.size(); i++) {
      string &a = words[i-1], &b = words[i];
      for(int j = 0; j < min(a.size(), b.size()); j++) 
        if(a[j] != b[j]) {
          m[a[j]].push_back(b[j]);
          cnt[b[j]]++;
          if(cnt.find(a[j]) == cnt.end()) cnt[a[j]] = 0;
          break;
        }
    }
    string ans;
    queue<char> q;
    for(auto &p:cnt) 
      if(!p.second) q.push(p.first);
    while(!q.empty()) {
      char t = q.front();
      q.pop();
      ans.push_back(t);
      for(auto &w:m[t]) {
        cnt[w]--;
        if(!cnt[w]) q.push(w);
      } 
    }
    return ans;
  }
};
