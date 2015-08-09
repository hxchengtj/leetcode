class Solution {
public:
    int singleNumber(int A[], int n) {
        int i, j, m = 32, a;
        unsigned t;
        char num[m];
        for(i = 0; i < m; i++)
            num[i] = 0;
        for(i = 0; i < n; i++) {
            t = A[i];
            for(j = 0; j < m; j++) {
                num[j] = (num[j] + (t & 1) )%3;
                t = (t >> 1);
            }
        }
        a = 0;
        for(i = m-1; i >= 0; i--) {
            a += num[i];
            if(i > 0)
                a = (a << 1);
        }
        return a;
    }
};

//version2
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int a = 0, b = 0;
        for(int i = 0; i < nums.size(); i++) {
            int t = (~a & b & nums[i]) | (a & ~b & ~nums[i]);
            b = (~a & ~b & nums[i]) | (~a & b & ~nums[i]);
            a = t;
        }
        return b;
    }
};

//redo
int singleNumber(vector<int>& nums) {
  int a = 0, b = 0;
  for(auto c:nums) {
    //******
    int t = (~a & b & c) | (a & ~b & ~c);
    b = (~a & ~b & c) | (~a & b & ~c);
    a = t;
  }
  return b;
}

