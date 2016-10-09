class Solution {
public:
    int findNthDigit(int n) {
        if(n <= 0) return 0;
        long long a = 9, i = 1, ans = 1;
        while(n > a*i) {
            n -= a*i;
            ans *= 10;
            a *= 10;
            i++;
        }
        ans += (n-1)/i;
        int j = i-(n-1)%i;
        while(j-- > 1) ans /= 10;
        return ans%10;
    }
};
