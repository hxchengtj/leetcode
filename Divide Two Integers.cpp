// review
class Solution {
public:
    int divide(int dividend, int divisor) {
        long long a = dividend, b = divisor, l, r, m;
        int ans;
        bool pos = false;
        if((a < 0 && b > 0) || (a > 0 && b < 0))
            pos = true;
        if(a < 0)   a = -a;
        if(b < 0)   b = -b;
        l = 0;
        r = a;
        while(l <= r) {
            m = (l + r) >> 1;
            if(mul(m, b) <= a)
                l = m+1;
            else
                r = m-1;
        }
        l--;
        if(pos) {
            l = -l;
            if(l < INT_MIN)
                l = INT_MIN;
        }
        if(l > INT_MAX)
            l = INT_MAX;
        return l;
    }
    long long mul(long long x, long long y) {
        long long ret = 0;
        while(y) {
            if(y & 1)
                ret += x;
            x = x << 1;
            y = y >> 1;
        }
        return ret;
    }
};