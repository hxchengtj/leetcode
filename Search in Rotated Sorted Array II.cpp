// review
class Solution {
public:
    bool search(int A[], int n, int target) {
        int l = 0, r = n-1, m;
        while(l <= r) {
            m = (l+r)/2;
            if(A[m] == target) return true;
            if(A[l] < A[m]) {
                if(A[m] < target)
                    l = m+1;
                else if(A[l] <= target) 
                    r = m-1;
                else
                    l = m+1;
            }
            else if(A[l] > A[m]) {
                if(A[m] > target)
                    r = m-1;
                else if(A[r] >= target)
                    l = m+1;
                else
                    r = m-1;
            }
            else
                l++;
        }
        return false;
    }
};