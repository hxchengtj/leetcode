/* review again */
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> f(target+1);
        f[0] = 1;
        for(int i = 1; i <= target; i++)
            for(int num:nums) 
                if(num <= i)
                f[i] += f[i-num];
        return f[target];
    }
};
