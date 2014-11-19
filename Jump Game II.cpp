class Solution {
public:
    int jump(int A[], int n) {
        int i, j = 0, k = 0, ans = 0;
        for (i = 0; i < n; i++)
           if(i <= j)
                k = max(A[i]+i, k);
            else {
                ans++;
                if(k < i)
                    return -1;
                j = k;
                k = A[i]+i;
            }
        return ans;
    }
};