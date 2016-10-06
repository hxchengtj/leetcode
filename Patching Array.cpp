/* review again */
class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long a = 0; 
        int ans = 0, i = 0, m = nums.size();
        while(a < n && i < m) {
            while(a < n && a+1 < nums[i]) {
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

//version2
class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long missed = 1;
        int ans = 0, i = 0, m = nums.size();
        while(missed <= n) {
            if(i < m && missed >= nums[i]) {
                missed += nums[i++];
            } else {
                missed += missed;
                ans++;
            }
        }
        return ans;
    }
};
