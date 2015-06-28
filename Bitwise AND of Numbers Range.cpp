class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int r = n-m+1;
        int a = m & n, b = -1;
        for(int i = 1; i > 0 && i < r; i = i<<1)
            b = b << 1;
        a = a & b;
        return a;
    }
};