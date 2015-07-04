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

//redo
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