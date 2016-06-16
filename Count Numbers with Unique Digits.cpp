class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        int A[11];
        A[0] = 1;
        A[1] = 9;
        for (int i = 2; i <= 10; i++) A[i] = (10-i+1)*A[i-1];
        int ans = 0;
        for (int i = 0; i <= min(10, n); i++) {
            ans += A[i];
        }
        return ans;
    }
};
