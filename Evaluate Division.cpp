class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> query) {
        unordered_map<string, vector<pair<string, double>>> MAP;
        unordered_set<string> SET;
        for(int i = 0; i < equations.size(); i++) {
            MAP[equations[i].first].push_back({equations[i].second, values[i]});
            if(values[i] != 0) MAP[equations[i].second].push_back({equations[i].first, 1/values[i]});
            SET.insert(equations[i].first);
            SET.insert(equations[i].second);
        }
        vector<double> ans;
        for(auto &p:query) {
            if(SET.find(p.first) == SET.end() || SET.find(p.second) == SET.end()) {
                ans.push_back(-1.0);
            } else {
                queue<pair<string, double>> q; 
                unordered_set<string> visited;
                q.push({p.first, 1.0});
                visited.insert(p.first);
                bool canCal = false;
                while(!q.empty()) {
                    auto t = q.front();
                    q.pop();
                    if(t.first == p.second) {
                        ans.push_back(t.second);
                        canCal = true;
                        break;
                    } else {
                        for(auto &a:MAP[t.first]) {
                            if(visited.find(a.first) == visited.end()) {
                                visited.insert(a.first);
                                q.push({a.first, t.second*a.second});
                            } 
                        }
                    }
                }
                if(!canCal) ans.push_back(-1.0);
            }
        }
        return ans;
    }
};
