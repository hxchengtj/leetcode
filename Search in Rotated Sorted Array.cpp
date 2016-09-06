// review
class Solution {
public:
    int search(int A[], int n, int target) {
        int l = 0, r = n-1, m;
        while(l<=r) {
            m = (l+r)/2;
            if (A[m] == target) return m;
            if (A[l] <= A[m]) {
                if(A[m] < target)
                    l = m+1;
                else if(A[l] <= target)
                    r = m-1;
                else
                    l = m+1;
            }
            else {
                if(A[m] > target)
                    r = m-1;
                else if(A[r] >= target)
                    l = m+1;
                else
                    r = m-1;
            }
        }
        return -1;
    }
};

//version2
class Solution {
public:
    int __search(vector<int>& nums, int target, int l, int r) {
        while(l < r) {
            int m = l + (r-l)/2;
            if(nums[m] < target) l = m+1;
            else if(nums[m] > target) r = m;
            else return m;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size();
        while(l < r) {
            int m = l + (r-l)/2;
            if(nums[m] < nums[l]) r = m;
            else {
                l = m+1;
                if(l < r && nums[l] < nums[m]) break;
            }
        }
        return max(__search(nums, target, 0, l), __search(nums, target, l, nums.size()));
    }
};


//version2
//redo
int __search(vector<int>& nums, int l, int r, int target) {
  while(l < r) {
    int m = l + (r-l)/2;
    if(nums[m] > target) r = m;
    else if(nums[m] < target) l = m+1;
    else return m;
  }
  return -1;
}
int search(vector<int>& nums, int target) {
  int n = nums.size();
  int l = 0, r = n, m = 0;
  while(l < r) {
    m = l + (r-l)/2;
    if(nums[m] < nums[l]) r = m;
    else {
      if(m == n-1 || nums[m] > nums[m+1]) break;
      else l = m+1;
    }
  }
  return max(__search(nums, 0, m+1, target), __search(nums, m+1, n, target));
}

//redo
class Solution {
public:
    int __search(vector<int>& nums, int l, int r, int target) {
        while(l <= r) {
            int m = l + (r-l)/2;
            if(nums[m] == target) return m;
            else if(nums[m] < target) l = m+1;
            else r = m-1;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size(), l = 0, r = n-1;
        while(l <= r) {
            int m = l + (r-l)/2;
            if(nums[0] <= nums[m]) l = m+1;
            else r = m-1;
        }
        return max(__search(nums, 0, l-1, target), __search(nums, l, n-1, target));
    }
};
