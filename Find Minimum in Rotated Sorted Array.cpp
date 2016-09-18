/* review again */
class Solution {
public:
    int findMin(vector<int> &num) {
        int l = 0, r = num.size()-1, mid, ans = INT_MAX;
        while (l <= r) {
            mid = (l+r)/2;
            ans = min(ans, num[l]);
            if(num[l] <= num[mid])
                l = mid+1;
            else
                r = mid;
        }
        return ans;
    }
};

//redo
int findMin(vector<int>& nums) {
  int l = 0, r = nums.size()-1;
  while(l < r) {
    int m = l+(r-l)/2;
    if(nums[m] > nums[r]) l = m+1;
    else r = m;
  }
  return nums[l];
}

//redo
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return -1;
        int l = 0, r = n-1;
        while(l <= r) {
            int m = (l+r)/2;
            if(nums[m] > nums[n-1]) l = m+1;
            else r = m-1;
        }
        return nums[l];
    }
};
