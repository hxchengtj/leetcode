// review
// divide and conquer???
class Solution {
public:
    int maxSubArray(int A[], int n) {
        int i;
        int sum = 0, maxsum = INT_MIN;
        for(i = 0; i < n; i++) {
            sum += A[i];
            maxsum = max(maxsum, sum);
            if(sum < 0)
                sum = 0;
        }
        return maxsum;
    }
};

//version2
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int sum = nums[0], ret = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            sum = max(sum+nums[i], nums[i]);
            ret = max(ret, sum);
        }
        return ret;
    }
};

//redo
int maxSubArray(vector<int>& nums) {
  if(nums.size() == 0) return 0;
  int maxsum = nums[0], sum = nums[0];
  for(int i = 1; i < nums.size(); i++) {
    sum = max(0, sum)+nums[i];
    maxsum = max(maxsum, sum);
  }
  return maxsum;
}

