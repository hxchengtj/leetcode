class Solution {
public:
    bool canJump(int A[], int n) {
        int i, j = 0;
        for(i = 0; i <= j && j < n; i++)
            j = max(j, i+A[i]);
        return j >= (n-1);
    }
};

//redo
bool canJump(vector<int>& nums) {
  int len = 0, n = nums.size();
  for(int i = 0; i < n; i++) {
    if(len < i) return false;
    len = max(len, i+nums[i]);
  }
  return true;
}


