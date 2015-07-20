class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;
        int a = 1, n = nums.size();
        for(int i = 0; i < n; i++) {
            ans.push_back(a);
            a *= nums[i];
        }
        a = 1;
        for(int i = n-1; i >= 0; i--) {
            ans[i] *= a;
            a *= nums[i];
        }
        return ans;
    }
};