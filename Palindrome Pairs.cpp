/* review again */
//review
class Solution {
public:
    bool isP(string &s) {
        int i = 0, j = s.size()-1;
        while(i < j) {
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    vector<vector<int>> palindromePairs(vector<string>& words) {
        int n = words.size();
        if (n < 2) return {};
        vector<vector<int>> ans;
        unordered_map<string, int> m;
        for(int i = 0; i < n; i++) m[words[i]] = i;
        for(int i = 0; i < n; i++) {
            string rs = words[i];
            reverse(rs.begin(), rs.end());
            for(int j = 0; j <= rs.size(); j++) {
                string subs1 = rs.substr(j), subs2 = rs.substr(0, j);
                if(m.find(subs1) != m.end() && m[subs1] != i && isP(subs2)) {
                    if(j != 0 || m[subs1] > i) ans.push_back({i, m[subs1]});
                }
                if (m.find(subs2) != m.end() && m[subs2] != i && isP(subs1)) {
                    if(j != rs.size() || m[subs2] > i) ans.push_back({m[subs2], i});
                }
            }
        }
        return ans;
    }
};
