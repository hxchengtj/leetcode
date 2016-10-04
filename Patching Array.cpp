/* review again */
class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long a = 0; 
        int ans = 0, i = 0, m = nums.size();
        while(a < n && i < m) {
            while(a+1 < nums[i]) {
                a += a+1;
                ans++;
            }
            a += nums[i];
            i++;
        }
        while(a < n) {
            a += a+1;
            ans++;
        }
        return ans;
    }
};
