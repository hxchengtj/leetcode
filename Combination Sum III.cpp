class Solution {
public:
    vector<vector<int> > ans;
    vector<int> v;
    vector<vector<int>> combinationSum3(int k, int n) {
        ans.clear();
        v.clear();
        dfs(k, n, 1);
        return ans;
    }
    void dfs(int k, int n, int a) {
        if(k <= 1) {
            if(n >= a && n <= 9 && n >= 1) {
                v.push_back(n);
                ans.push_back(v);
                v.pop_back();
            }
            return;
        }
        for(int i = a; i <= 9; i++) {
            v.push_back(i);
            dfs(k-1, n-i, i+1);
            v.pop_back();
        }
    }
};

