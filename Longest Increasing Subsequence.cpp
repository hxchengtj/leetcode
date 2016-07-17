class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        vector<int> f(n, INT_MAX);
        int ans = 0;
        for(int i = 0; i < n; i++) {
            int l = 0, r = i;
            while(l < r) {
                int m = l+(r-l)/2;
                if(f[m] < nums[i]) l = m+1;
                else r = m;
            }
            f[l] = min(f[l], nums[i]);
            ans = max(ans, l+1);
        }
        return ans;
    }
};
