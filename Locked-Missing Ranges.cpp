class Solution {
public:
  vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
    int l = lower, n = nums.size();
    vector<string> ans;
    for(int i = 0; i < n; i++) {
      if(nums[i] == l) {
        l += 1;
      } else {
        if(l == nums[i]-1) ans.push_back(to_string(l));
        else if(l < nums[i]-1) ans.push_back(to_string(l)+"->"+to_string(nums[i]-1));
        l = nums[i]+1;
      }
    }
    if(l == upper) ans.push_back(to_string(l));
    else if(l < upper) ans.push_back(to_string(l)+"->"+to_string(upper));
    return ans;
  }
};
