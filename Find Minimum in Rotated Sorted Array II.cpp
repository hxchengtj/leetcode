// review
class Solution {
public:
    int findMin(vector<int> &num) {
        int l = 0, r = num.size()-1, m;
        while(l <= r && num[l] >= num[r]) {
            m = (l+r) / 2;
            if(num[l] > num[m])
                r = m;
            else if(num[r] < num[m])
                l = m+1;
            else
                r = r-1;
        }
        return num[l];
    }
};

//redo
int findMin(vector<int>& nums) {
  int l = 0, r = nums.size()-1;
  while(l < r) {
    int m = l+(r-l)/2;
    if(nums[m] > nums[r]) l = m+1;
    else if(nums[m] == nums[r]) r--;
    else r = m;
  }
  return nums[l];
}

