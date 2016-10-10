/* review again */
class Solution {
public:
    bool __splitArray(vector<int>& nums, int mid, int m) {
        int j = 0, sum = 0, cnt = 1;
        while(j < nums.size()) {
            if(sum <= mid-nums[j]) 
                sum += nums[j++];
            else if(nums[j] > mid) return false;
            else {
                cnt++;
                sum = nums[j];
                j++;
            }
        }
        return cnt <= m;
    }
    int splitArray(vector<int>& nums, int m) {
        int l = 0, n = nums.size(), r = 0;
        for(int i = 0; i < m-1; i++) r = max(r, nums[i]);
        int sum = 0;
        for(int i = m-1; i < n; i++) sum += nums[i];
        r = max(r, sum);
        while(l < r) {
            int mid = l + (r-l)/2;
            if(__splitArray(nums, mid, m)) r = mid;
            else l = mid+1;
        }
        return l;
    }
    
};
