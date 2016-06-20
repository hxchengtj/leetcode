class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int f[2] = {INT_MAX, INT_MAX};
        for(int i = 0; i < nums.size(); i++) {
            if (f[1] < nums[i]) return true;
            if(f[0] < nums[i]) f[1] = min(f[1], nums[i]);
            f[0] = min(f[0], nums[i]);
        }
        return false;
    }
};
