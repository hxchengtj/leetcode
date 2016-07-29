class Solution {
public:
  vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
    a_ = a; b_ = b; c_ = c;
    int n = nums.size();
    vector<int> ans(n);
    int i = 0, j = n-1, k = a < 0 ? 0 : n-1;;
    while(i <= j) {
      if(a < 0) 
        ans[k++] = f(nums[i]) < f(nums[j])? f(nums[i++]):f(nums[j--]);
      else
        ans[k--] = f(nums[i]) > f(nums[j])? f(nums[i++]):f(nums[j--]);
    } 
    return ans;
  }
  int f(int x) {
    return a_ * x * x + b_ * x + c_;
  }
private:
  int a_, b_, c_;
};
