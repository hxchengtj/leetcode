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


//version2

class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN && divisor == -1 || divisor == 0) return INT_MAX;

        bool isNeg = (dividend < 0) ^ (divisor < 0);
        dividend = dividend > 0? -dividend:dividend;
        divisor = divisor > 0 ? -divisor:divisor;
        int shift = 0, ans = 0;
        while(shift < 32 && (divisor << shift) < 0 && dividend <= (divisor << shift)) shift++;
        while(--shift >= 0) {
            if(dividend <= (divisor << shift)) {
                dividend -= (divisor << shift);
                ans |= (1 << shift);
            }
        }

        return isNeg? -ans:ans;
    }
};

//version2
//redo
int divide(int dividend, int divisor) {
  if(divisor == 0 || (dividend == INT_MIN && divisor == -1)) return INT_MAX;

  bool isNeg = (dividend < 0) ^ (divisor < 0);
  dividend = dividend < 0 ? dividend:-dividend;
  divisor = divisor < 0 ? divisor:-divisor;
  int ans = 0, i = 0;
  while(i <= 31 && ((divisor << i) < 0 && dividend <= (divisor << i))) i++;
  while(--i >= 0) {
    if(dividend <= (divisor << i)) {
      dividend -= (divisor << i);
      ans += (1 << i);
    }
  }
  return isNeg? -ans : ans;
}

