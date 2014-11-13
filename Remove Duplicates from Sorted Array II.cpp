class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(!n)
            return 0;
        int i, length = 1, dup = 1;
        for(i = 1 ; i < n; i++) 
            if(A[i] != A[i-1]) {
                dup = 1;
                A[length] = A[i];
                length++;
            }
            else if(A[i] == A[i-1] && dup == 1) {
                dup++;
                A[length] = A[i];
                length++;
            }
        return length;
    }
};