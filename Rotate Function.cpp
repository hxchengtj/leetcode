class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        int n = A.size();
        if(n <= 1) return 0;
        int sum = 0, ans = INT_MIN, sum1 = 0;
        for(int i = 0; i < n-1; i++) {
            sum += i*A[i];
            sum1 += A[i];
        }
        for(int i = 0; i < n; i++) {
            ans = max(ans, sum + (n-1)*A[n-1-i]);
            sum = sum+sum1-(n-1)*A[(2*n-i-2)%n];
            sum1 = sum1 - A[(2*n-i-2)%n] + A[n-1-i];
        }
        return ans;
    }
};
