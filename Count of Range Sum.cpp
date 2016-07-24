class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        vector<long long> sum(n+1);
        for(int i = 0; i < n; i++) sum[i+1] = sum[i]+nums[i];
        return mergeCount(sum, 0, n+1, lower, upper);
    }
    int mergeCount(vector<long long>& sum, int l, int r, int lower, int upper) {
        if(r-l <= 1) return 0;
        int m = l+(r-l)/2;
        int cnt = mergeCount(sum, l, m, lower, upper) + mergeCount(sum, m, r, lower, upper);
        int i = l, j = m, k = m, ii = 0, jj = m;
        vector<long long> tmp(r-l);
        for(i = l; i < m; i++) {
            while(j < r && sum[j]-sum[i] < lower) j++;
            while(k < r && sum[k]-sum[i] <= upper) k++;
            while(jj < r && sum[jj] < sum[i]) tmp[ii++] = sum[jj++];
            tmp[ii++] = sum[i];
            cnt += k-j;
        }
        for(i = 0; i < ii; i++) sum[i+l] = tmp[i];
        return cnt;
    }
};
