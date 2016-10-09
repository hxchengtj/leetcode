class Solution {
public:
    bool dfs(vector<int>& nums, int idx, int sum) {
        if(sum == 0) return true;
        int n = nums.size();
        for(int i = idx; i < n && nums[i] <= sum; i++) {
            if(dfs(nums, i+1, sum-nums[i]))
                return true;
        }
        return false;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1) return false;
        int sum = 0;
        for(auto &a:nums) sum += a;
        if(sum%2 == 1) return false;
        sort(nums.begin(), nums.end());
        return dfs(nums, 0, sum/2);
    }
};
