class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        int f[n][2], ans = 0;
        for(int i = 0; i < n; i++) {
            f[i][0] = f[i][1] = 1;
            for(int j = 0; j < i; j++) {
                if(nums[j] < nums[i]) f[i][0] = max(f[i][0], f[j][1]+1);
                else if(nums[j] > nums[i]) f[i][1] = max(f[i][1], f[j][0]+1);
            }
            ans = max({ans, f[i][0], f[i][1]});
        }
        return ans;
        
    }
};
