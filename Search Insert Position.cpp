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

//redo
int searchInsert(vector<int>& nums, int target) {
  int l = 0, r = nums.size();
  while(l < r) {
    int m = l + (r-l)/2;
    if(nums[m] < target) l = m+1;
    else r = m;
  }
  return l;
}


