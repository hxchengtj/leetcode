class Solution {
public:
  int maxSubArrayLen(vector<int>& nums, int k) {
    unordered_map<int, int> m;
    m[0] = -1;
    int sum = 0, ans = 0;
    for(int i = 0; i < nums.size(); i++) {
      sum += nums[i];
      if(m.find(sum-k) != m.end()) ans = max(ans, i-m[sum-k]);
      if(m.find(sum) == m.end()) m[sum] = i;
    }
    return ans;
  }
};
