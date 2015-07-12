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


//version2
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        int i = 0, j = 0, k = (m+n-1)/2;
        int t = (m + n) & 1 ? 1:2;
        int ans = 0;
        for(int x = 0;x < t; x++) {
            while(k && i < m && j < n) {
                int k1 = min(i+(k-1)/2, m-1), k2 = min(j+(k-1)/2, n-1);
                if(nums1[k1] > nums2[k2]) {
                    k = k - (k2-j+1);
                    j = k2+1;
                }
                else {
                    k = k - (k1-i+1);
                    i = k1+1;
                }
            }
            if(i == m) {
                ans += nums2[j+k]; 
                j += k+1;
            }
            else if(j == n) {
                ans += nums1[i+k];
                i += k+1;
            }
            else {
                if(nums1[i] < nums2[j]) {
                    ans += nums1[i];
                    i++;
                }
                else {
                    ans += nums2[j];
                    j++;
                }
            }
            k = 0;
        }
        return (double)ans/t;
    }
};