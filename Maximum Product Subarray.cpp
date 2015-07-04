class Solution {
public:
    int maxProduct(int A[], int n) {
        int i, maxp = A[0], p1 = A[0], p2 = A[0], t;
        for(i = 1; i < n; i++) {
            t = p1;
            p1 = min(p1*A[i], p2*A[i]);
            p1 = min(A[i], p1);
            p2 = max(t*A[i], p2*A[i]);
            p2 = max(A[i], p2);
            maxp = max(maxp, p2);
        }
        return maxp;
    }
};

//redo
//review
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int ans = nums[0], maxval = nums[0], minval = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            int tmp = max({nums[i], nums[i]*maxval, nums[i]*minval});
            minval = min({nums[i], nums[i]*maxval, nums[i]*minval});
            maxval = tmp;
            ans = max(ans, maxval);
        }
        return ans;
    }
};