// hard
// review
class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        int i, j, k;
        for(i = 0; i < n; i++) {
            j = A[i];
            if(j >= 1 && j <= n && A[j-1] != j) {
                k = A[j-1];
                A[j-1] = j;
                A[i] = k;
                i--;
            }
        }
        for(i = 0; i < n; i++)
            if(A[i] != i+1)
                return i+1;
        return n+1;
    }
};

//redo
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        while(i < n){
            if(nums[i] >= 1 && nums[i] <= n && nums[nums[i]-1] != nums[i])
                swap(nums[nums[i]-1], nums[i]);
            else i++;
        }
        for(int i = 0; i < n; i++)
            if(nums[i] != i+1) return i+1;
        return n+1;
    }
};


//redo2
int firstMissingPositive(vector<int>& nums) {
  int n = nums.size(), i = 0;
  while(i < n) {
    if(nums[i] <= n && nums[i] >= 1 && nums[nums[i]-1] != nums[i])
      swap(nums[nums[i]-1], nums[i]);
    else i++;
  }
  for(i = 0; i < n; i++)
    if(nums[i] != i+1) return i+1;
  return n+1;
}

