class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        int l = 0, r = n-1, m;
        while(l <= r) {
            m = (l+r)/2;
            if(A[m] < target)
                l = m+1;
            else 
                r = m-1;
        }
        return l;
    }
};
