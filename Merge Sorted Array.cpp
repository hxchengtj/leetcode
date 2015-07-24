class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int i = m-1, j = n-1, k = m+n-1;
        while(i >= 0 && j >= 0) {
            if(A[i] > B[j]) {
                A[k] = A[i];
                i--;
            }
            else {
                A[k] = B[j];
                j--;
            }
            k--;
        }
        while(i >= 0) {
            A[k] = A[i];
            k--;
            i--;
        }
        while(j >= 0) {
            A[k] = B[j];
            k--;
            j--;
        }
    }
};

//redo
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
  int i = m-1, j = n-1, k = m+n-1;
  while(i >= 0 && j >= 0) {
    if(nums1[i] > nums2[j]) nums1[k--] = nums1[i--];
    else nums1[k--] = nums2[j--];
  }
  while(j >= 0) nums1[k--] = nums2[j--];
}

