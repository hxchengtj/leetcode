class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(!n)
            return 0;
        int i = 0, length = 1;
        for(i = 1; i < n; i++) {
            if(A[i] != A[i-1]) {
                A[length] = A[i];
                length++;
            }
        }
        return length;
    }
};

//redo
int removeDuplicates(vector<int>& nums) {
  if(nums.size() == 0) return 0;
  int a = nums[0], j = 1;
  for(int i = 1; i < nums.size(); i++) {
    if(nums[i] != a) {
      a = nums[i];
      nums[j++] = nums[i];
    }
  }
  nums.resize(j);
  return j;
}


