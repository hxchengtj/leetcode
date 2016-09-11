class Solution {
    vector<pair<int, int>> v;
public:
    Solution(vector<int> nums) {
        for(int i = 0; i < nums.size(); i++) v.push_back({nums[i], i});
        sort(v.begin(), v.end());
    }
    
    int pick(int target) {
        auto p = find_bound(target);
        int n = p.second-p.first+1;
        return v[p.first+rand()%n].second;
    }
private:
    pair<int, int> find_bound(int target) {
        int l = 0, r = v.size()-1, lower, upper;
        while(l <= r) {
            int m = l+(r-l)/2;
            if(v[m].first < target) l = m+1;
            else r = m-1;
        }
        lower = l;
        r = v.size()-1;
        while(l <= r) {
            int m = l+(r-l)/2;
            if(v[m].first <= target) l = m+1;
            else r = m-1;
        }
        upper = r;
        return make_pair(lower, upper);
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */
