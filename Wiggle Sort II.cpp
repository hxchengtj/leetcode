class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        nth_element(nums.begin(), nums.begin()+n/2, nums.end());
        int mid = nums[n/2];
        #define A(i) nums[(2*i+1)%(n|1)]
        int i = 0, j = 0, k = n-1;
        while(j <= k) {
            if(A(j) > mid) swap(A(i++), A(j++));
            else if(A(j) < mid) swap(A(j), A(k--));
            else j++;
        }
    }
};
