/* review again */
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


//redo
double findMedianSorted(vector<int>& nums1, vector<int>& nums2) {
  int m = nums1.size(), n = nums2.size();
  int t = (m+n)%2 == 0?2:1, k = (m+n-1)/2;
  int l1 = 0, l2 = 0;
  double ans = 0;
  while(t-- > 0) {
    while(k && l1 < m && l2 < n) {
      int k1 = min(l1+(k-1)/2, m-1);
      int k2 = min(l2+(k-1)/2, n-1);
      if(nums1[k1] < nums2[k2]) {
        k = k-(k1-l1+1);
        l1 = k1+1;
      } else {
        k = k-(k2-l2+1);
        l2 = k2+1;
      }
    }
    if(l1 == m) {
      ans += nums2[l2+k];
      l2 = l2+k+1;
    } else if(l2 == n) {
      ans += nums1[l1+k];
      l1 += k+1;
    } else if(nums1[l1] <= nums2[l2]) {
      ans += nums1[l1++];
    } else ans += nums2[l2++];
    k = 0;
  }
  return (m+n)%2 == 0? ans/2:ans;
}

//version2
class Solution {
public:
    double findKth(vector<int>& nums1, vector<int>& nums2, int start1, int start2, int k) {
        int n1 = nums1.size(), n2 = nums2.size();
        if(start1 == n1) return nums2[start2+k-1];
        if(start2 == n2) return nums1[start1+k-1];
        if(k == 1) return min(nums1[start1], nums2[start2]);
        int i = min({n1-start1, n2-start2, k/2});
        if(nums1[start1+i-1] < nums2[start2+i-1])
            return findKth(nums1, nums2, start1+i, start2, k-i);
        else
            return findKth(nums1, nums2, start1, start2+i, k-i);
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        if((n1+n2)&1 == 1) 
            return findKth(nums1, nums2, 0, 0, (n1+n2)/2+1);
        else 
            return (findKth(nums1, nums2, 0, 0, (n1+n2)/2) + findKth(nums1, nums2, 0, 0, (n1+n2)/2+1)) / 2;
    }
};
