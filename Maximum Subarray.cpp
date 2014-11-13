// review
// divide and conquer???
class Solution {
public:
    int maxSubArray(int A[], int n) {
        int i;
        int sum = 0, maxsum = INT_MIN;
        for(i = 0; i < n; i++) {
            sum += A[i];
            maxsum = max(maxsum, sum);
            if(sum < 0) 
                sum = 0;
        }
        return maxsum;
    }
};
