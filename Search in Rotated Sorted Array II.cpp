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

//redo
class Solution {
  public:
    bool __search(vector<int>& nums, int l, int r, int target) {
      while(l < r) {
        int m = l+(r-l)/2;
        if(nums[m] == target) return true;
        else if(nums[m] < target) l = m+1;
        else r = m;
      }
      return false;
    }
    bool search(vector<int>& nums, int target) {
      int n = nums.size(), l = 0, r = n-1;
      while(l < r) {
        int m = l+(r-l)/2;
        if(nums[m] < nums[r]) r = m;
        else if(nums[m] > nums[r]) l = m+1;
        else if(nums[m] == nums[l]) {
          if(nums[r-1] > nums[r]) l = r;
          else r--;
        }
        else r = m;
      }
      return __search(nums, 0, l, target) || __search(nums, l, n, target);
    }


};
