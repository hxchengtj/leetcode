class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];
        int f[nums.size()][2];
        f[0][0] = 0;
        f[0][1] = nums[0];
        f[1][0] = nums[1];
        f[1][1] = nums[0];
        int i;
        for(i = 2; i < nums.size()-1; i++) {
            f[i][0] = max(nums[i] + f[i-2][0], f[i-1][0]);
            f[i][1] = max(nums[i] + f[i-2][1], f[i-1][1]);
        }
        if (i >= 2) {
            f[i][0] = max(nums[i]+f[i-2][0], f[i-1][0]);
            f[i][1] = f[i-1][1];
        }
        return max(f[nums.size()-1][0], f[nums.size()-1][1]);
    }
};


//version2
class Solution {
public:
    int __rob(vector<int>& nums, int l, int r) {
        if(r-l <= 0) return 0;
        else if(r-l == 1) return nums[l];
        int f[2];
        f[l%2] = nums[l];
        f[(l+1)%2] = max(nums[l], nums[l+1]);
        for(int i = l+2; i < r; i++)
            f[i%2] = max(f[i%2]+nums[i], f[(i+1)%2]);
        return f[(r-1)%2];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        else if(n == 1) return nums[0];
        return max(__rob(nums, 0, n-1), __rob(nums, 1, n));
    }
};


//redo
int rob(vector<int>& nums) {
  if(nums.size() == 0) return 0;
  if(nums.size() == 1) return nums[0];
  return max(__rob(nums, 0, nums.size()-1), __rob(nums, 1, nums.size()));
}
int __rob(vector<int>& nums, int l, int r) {
  int f[nums.size()+1];
  f[l] = 0; f[l+1] = nums[l];
  for(int i = 2; i < r; i++)
    f[i+1] = max(f[i], f[i-1]+nums[i]);
  return f[r];
}

