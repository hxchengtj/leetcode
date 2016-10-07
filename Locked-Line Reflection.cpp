/* review again */
class Solution {
public:
  bool isReflected(vector<pair<int, int>>& points) {
    if(points.empty()) return true;
    int minp = min_element(points.begin(), points.end())->first;
    int maxp = max_element(points.begin(), points.end())->first;
    unordered_map<int, unordered_set<int>> m;
    for(auto& p:points) m[p.first].insert(p.second);
    for(auto& p:points) {
      int t = minp+maxp-p.first;
      if(m.find(t) == m.end() || m[t].find(p.second) == m[t].end()) return false;
    }
    return true;
  }
};
