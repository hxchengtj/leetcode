int missingNumber(vector<int>& nums) {
  int n = nums.size(), i = 0;
  while(i < n) {
    if(nums[i] >= 0 && nums[i] < n && nums[nums[i]] != nums[i])
      swap(nums[nums[i]], nums[i]);
    else i++;
  }
  for(i = 0; i < n; i++)
    if(nums[i] != i) return i;
  return n;
}

