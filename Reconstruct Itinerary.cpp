/* review again */
class Solution {
public:
    bool dfs(unordered_map<string, map<string, int>> & MAP, vector<string> &v, int n) {
        if(n == 0) return true;
        for(auto & p:MAP[v.back()]) {
            if (p.second > 0) {
                v.push_back(p.first);
                p.second--;
                if(dfs(MAP, v, n-1)) return true;
                v.pop_back();
                p.second++;
            }
        }
        return false;
    }
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        unordered_map<string, map<string, int>> MAP;
        for (auto &p:tickets) MAP[p.first][p.second]++;
        vector<string> v(1, "JFK");
        int n = tickets.size();
        dfs(MAP, v, n);
        return v;
    }
};
