/* review again */
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        nth_element(nums.begin(), nums.begin()+n/2, nums.end());
        int mid = nums[n/2];
        // 注意此处的定义 A(0), A(1), ... A(n)对应 nums[1], nums[3], ... nums[0], nums[2], ... 
        #define A(i) nums[(2*i+1)%(n|1)]
        int i = 0, j = 0, k = n-1;
        // 注意此处的变换
        while(j <= k) {
            if(A(j) > mid) swap(A(i++), A(j++));
            else if(A(j) < mid) swap(A(j), A(k--));
            else j++;
        }
    }
};
