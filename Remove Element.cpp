class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int l = n;
        for(int i = 0; i < l; i++) {
            if(A[i] == elem) {
                swap(A[i], A[l-1]);
                l--;
                i--;
            }
        }
        return l;
    }
};
