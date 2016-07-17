class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if(n == 0) return {};
        vector<pair<int, int>> v(n);
        int ans_index = 0;
        for(int i = 0; i < n; i++) {
            v[i] = make_pair(1, -1);
            for(int j = 0; j < i; j++) {
                if((nums[i] % nums[j]) == 0) {
                    if(v[i].first < v[j].first+1) {
                        v[i].first = v[j].first+1;
                        v[i].second = j;
                    }
                }
                if(v[i].first > v[ans_index].first) ans_index = i;
            }
        }
        vector<int> ans;
        while(ans_index != -1) {
            ans.push_back(nums[ans_index]);
            ans_index = v[ans_index].second;
        }
        return ans;
    }
};
