class Solution {
public:
    double pow(double x, int n) {
        if(n == 0)
            return 1;
        bool neg = false;
        if(n < 0) {
            n = -n;
            neg = true;
        }
        double t = pow(x, n/2);
        if(n%2 == 1)
            t = t*t*x;
        else
            t = t*t;
        if(neg)
            t = 1/t;
        return t;
    }
};


//version2
class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1;
        double a = x;
        int m = n >= 0? n: -(n+1);
        for(int i = 0; i < 31; i++) {
            if( (m&(1<<i)) != 0) ans *= a;
            a = a*a;
        }
        ans = n >= 0? ans:1/ans/x;
        return ans;
    }
};