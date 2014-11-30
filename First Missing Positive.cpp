// hard 
// review
class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        int i, j, k;
        for(i = 0; i < n; i++) {
            j = A[i];
            if(j >= 1 && j <= n && A[j-1] != j) {
                k = A[j-1];
                A[j-1] = j;
                A[i] = k;
                i--;
            }
        } 
        for(i = 0; i < n; i++)
            if(A[i] != i+1)
                return i+1;
        return n+1;
    }
};