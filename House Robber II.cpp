class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];
        int f[nums.size()][2];
        f[0][0] = 0;
        f[0][1] = nums[0];
        f[1][0] = nums[1];
        f[1][1] = nums[0];
        int i;
        for(i = 2; i < nums.size()-1; i++) {
            f[i][0] = max(nums[i] + f[i-2][0], f[i-1][0]);
            f[i][1] = max(nums[i] + f[i-2][1], f[i-1][1]);
        }
        if (i >= 2) {
            f[i][0] = max(nums[i]+f[i-2][0], f[i-1][0]);
            f[i][1] = f[i-1][1];
        }
        return max(f[nums.size()-1][0], f[nums.size()-1][1]);
    }
};