class Solution {
public:
    void sortColors(int A[], int n) {
        int i, j, k;
        int f[3] = {-1,-1,-1};
        f[A[0]] = 0;
        for(i = 1; i < n; i++) {
            if(A[i] >= A[i-1]) {
                if(f[A[i]] == -1)
                    f[A[i]] = i;
            }
            else  {
                j = A[i]+1;
                while(j<=2 && f[j] == -1)
                    j++;
                k = f[j];
                if(A[k+1] == A[k])
                    f[j] = k+1;
                else
                    f[j] = -1;
                if(f[A[i]] == -1)
                    f[A[i]] = k;
                swap(A[k], A[i]);
                i--;
            }  
        }
    }
};
