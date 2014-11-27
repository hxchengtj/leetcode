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
