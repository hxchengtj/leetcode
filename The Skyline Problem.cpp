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
            else  {
                if(m.find(t) != m.end())
                    m[t]++;
                else
                    m.insert(make_pair(t, 1));
            }
            if(i != v.size()-1 && b == v[i+1].first) 
                continue;
            if(m.empty())
                h = 0;
            else 
                h = (--m.end())->first;
            if(h != maxh)
                ret.push_back(make_pair(b, h));
            maxh = h;
        }
        return ret;
    }
};