class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(!n)
            return 0;
        int i, length = 1, dup = 1;
        for(i = 1 ; i < n; i++)
            if(A[i] != A[i-1]) {
                dup = 1;
                A[length] = A[i];
                length++;
            }
            else if(A[i] == A[i-1] && dup == 1) {
                dup++;
                A[length] = A[i];
                length++;
            }
        return length;
    }
};

//redo
int removeDuplicates(vector<int>& nums) {
  if(nums.size() == 0) return 0;
  int j = 1, count = 1;
  for(int i = 1; i < nums.size(); i++) {
    if(nums[i] == nums[i-1]) {
      if(++count <= 2) nums[j++] = nums[i];
    } else {
      nums[j++] = nums[i];
      count = 1;
    }
  }
  return j;
}

