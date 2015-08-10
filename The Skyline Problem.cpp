//redo
class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        map<int, int> m;
        vector<pair<int, int>> v;
        vector<pair<int, int>> ret;
        for(int i = 0; i < buildings.size(); i++) {
            int h = buildings[i][2];
            v.push_back(make_pair(buildings[i][0], h));
            v.push_back(make_pair(buildings[i][1], 0-h));
        }
        sort(v.begin(), v.end(), [](pair<int, int> a, pair<int, int> b) {
            return a.first < b.first;
        });

        int maxh = -1, b, t, h;
        for(int i = 0; i < v.size(); i++) {
            b = v[i].first;
            t = v[i].second;
            if(t < 0) {
                m[-t]--;
                if(m[-t] == 0)
                    m.erase(-t);
            }
            else
                m[t]++;
            if(i != v.size()-1 && b == v[i+1].first)
                continue;
            if(m.empty())
                h = 0;
            else
                h = prev(m.end())->first;
            if(h != maxh)
                ret.push_back(make_pair(b, h));
            maxh = h;
        }
        return ret;
    }
};

//redo
vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
  map<int, int> m;
  vector<pair<int, int>> v;
  vector<pair<int, int>> ans;
  for(auto &a:buildings) {
    v.push_back(make_pair(a[0], a[2]));
    v.push_back(make_pair(a[1], -a[2]));
  }
  sort(v.begin(), v.end(), [](const pair<int, int>& a, const pair<int, int>& b){
      if(a.first != b.first) return a.first < b.first;
      return a.second > b.second;
      });
  int h = 0;
  for(auto &a:v) {
    if(a.second > 0) m[a.second]++;
    else {
      m[-a.second]--;
      if(m[-a.second] == 0) m.erase(-a.second);
    }
    int maxh = 0;
    if(!m.empty()) maxh = prev(m.end())->first;
    if(h != maxh) ans.push_back(make_pair(a.first, maxh));
    h = maxh;
  }
  return ans;
}

