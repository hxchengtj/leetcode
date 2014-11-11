class Solution {
public:
    vector<vector<int> > ans;
    vector<int> v;
    vector<bool> s;
    vector<vector<int> > permute(vector<int> &num) {
        ans.clear();
        v.clear();
        s.clear();
        v.resize(num.size());
        s.resize(num.size());
        dfs(0, num);
        return ans;
    }
    void dfs(int x, vector<int> &num) {
        if(x == num.size()) {
            ans.push_back(v);
            return;
        }
        for(int i = 0; i < num.size(); i++) {
            if(s[i] == false) {
                s[i] = true;
                v[x] = num[i];
                dfs(x+1, num);
                s[i] = false;
            }
        }
    }
};