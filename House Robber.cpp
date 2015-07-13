class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0)    return 0;
        if(nums.size() == 1)    return nums[0];
        int f[nums.size()];
        f[0] = nums[0];
        f[1] = max(f[0], nums[1]);
        for(int i = 2; i < nums.size(); i++)
            f[i] = max(nums[i]+f[i-2], f[i-1]);
        return f[nums.size()-1];
    }
};

//version2
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0)    return 0;
        if(nums.size() == 1)    return nums[0];
        int f[2];
        f[0] = nums[0];
        f[1] = max(f[0], nums[1]);
        for(int i = 2; i < nums.size(); i++)
            f[i%2] = max(nums[i]+f[i%2], f[(i+1)%2]);
        return f[(nums.size()-1)%2];
    }
};