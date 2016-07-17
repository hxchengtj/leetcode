class Solution {
public:
    bool __findDuplicate(vector<int>& nums, int x) {
        int count = 0;
        for(int n:nums) 
            if(n <= x) count++;
        return count > x;
    }
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) return -1;
        int l = 1, r = n;
        while(l < r) {
            int m = l+(r-l)/2;
            if(__findDuplicate(nums, m)) r = m;
            else l = m+1;
        }
        return l;
    }
};
