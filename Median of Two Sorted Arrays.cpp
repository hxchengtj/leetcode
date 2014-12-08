// hard
// review
class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int i = (m+n+1)/2, j;
        double a, b;
        a = findkth(A, 0, m-1, B, 0, n-1, i);
        if((m+n)%2 == 0) {
            j = i+1;
            b = findkth(A, 0, m-1, B, 0, n-1, j);
            a = (a+b)/2;
        }
        return a;
    }
    double findkth(int A[], int al, int ar, int B[], int bl, int br, int k) {
        if(al > ar)
            return B[bl+k-1];
        if(bl > br)
            return A[al+k-1];
        int am = (al+ar)/2, bm = (bl+br)/2, t;
        t = (am-al) + (bm-bl) + 1;
        if(A[am] >= B[bm]) {
            if(t >=  k)
                return findkth(A, al, am-1, B, bl, br, k);
            else
                return findkth(A, al, ar, B, bm+1, br, k-(bm-bl)-1);
        }
        else {
            if(t >= k)
                return findkth(A, al, ar, B, bl, bm-1, k);
            else
                return findkth(A, am+1, ar, B, bl, br, k-(am-al)-1);
        }
    }
};