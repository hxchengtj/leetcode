/* review again */
class Solution {
public:
    void sortColors(int A[], int n) {
        int i, j, k;
        int f[3] = {-1,-1,-1};
        f[A[0]] = 0;
        for(i = 1; i < n; i++) {
            if(A[i] >= A[i-1]) {
                if(f[A[i]] == -1)
                    f[A[i]] = i;
            }
            else  {
                j = A[i]+1;
                while(j<=2 && f[j] == -1)
                    j++;
                k = f[j];
                if(A[k+1] == A[k])
                    f[j] = k+1;
                else
                    f[j] = -1;
                if(f[A[i]] == -1)
                    f[A[i]] = k;
                swap(A[k], A[i]);
                i--;
            }
        }
    }
};

//version2
//redo
void sortColors(vector<int>& nums) {
  int tail0 = 0, tail1 = 0;
  for(int i = 0; i < nums.size(); i++) {
    if(nums[i] == 0) {
      nums[i] = nums[tail1];
      nums[tail1++] = nums[tail0];
      nums[tail0++] = 0;
    }
    else if(nums[i] == 1) {
      nums[i] = nums[tail1];
      nums[tail1++] = 1;
    }
  }
}

//version3
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i = 0, j = 0, k = nums.size()-1;
        while(j <= k) {
            if(nums[j] == 0) swap(nums[i++], nums[j++]);
            else if(nums[j] == 2) swap(nums[j], nums[k--]);
            else j++;
        }
    }
};
