class Solution {
public:
    vector<vector<int> > ans;
    vector<int> v;
    vector<vector<int> > subsets(vector<int> &S) {
        sort(S.begin(), S.end());
        dfs(0, S);
        return ans;
    }
    void dfs(int a, vector<int> &S) {
        if(a >= S.size()) {
            ans.push_back(v);
            return;
        }
        if(a > 0 && S[a] == S[a-1]) {
            dfs(a+1, S);
            return;
        }
        v.push_back(S[a]);
        dfs(a+1, S);
        v.pop_back();
        dfs(a+1, S);
    }
};