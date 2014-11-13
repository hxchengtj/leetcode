class Solution {
public:
    bool canJump(int A[], int n) {
        int i, j = 0;
        for(i = 0; i <= j && j < n; i++) 
            j = max(j, i+A[i]);
        return j >= (n-1);
    }
};
