class Solution {
public:
    vector<vector<int>> ans;
    vector<int> v;
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        if(candidates.size() > 0)
            dfs(0, candidates, target);
        return ans;
    }
    void dfs(int a, vector<int> &candidates, int target) {
        if(target == 0) {
            ans.push_back(v);
            return;
        }
        for(int i = a; i < candidates.size() && candidates[i] <= target; i++) {
            v.push_back(candidates[i]);
            dfs(i, candidates, target-candidates[i]);
            v.pop_back();
        }
    }
};
