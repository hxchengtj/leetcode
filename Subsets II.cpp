class Solution {
public:
    vector<vector<int> > ans;
    vector<int> b;
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        sort(S.begin(), S.end());
        vector<pair<int, int> > v;
        int i;
        v.push_back(make_pair(S[0], 1));
        for(i = 1; i < S.size(); i++) {
            if(S[i] == S[i-1])
                v.back().second++;
            else
                v.push_back(make_pair(S[i], 1));
        }
        dfs(0, v);
        return ans;
    }
    void dfs(int a, vector<pair<int, int> > &v) {
        if(a >= v.size()) {
            ans.push_back(b);
            return;
        }
        int i;
        for(i = 0; i <= v[a].second; i++) {
            dfs(a+1, v);
            b.push_back(v[a].first);
        }
        for(i = 0; i <= v[a].second; i++)
            b.pop_back();
    }
};