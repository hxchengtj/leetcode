//review
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        int l = 0, r = 0, a = nums[0], n = nums.size(), b = n+1;
        while(r < n) {
            if(a < s) {
                r++;
                if(r < n)
                    a += nums[r];
            }
            else {
                b = min(b, r-l+1);
                a -= nums[l];
                l++;
            }
        }
        if(b > n)
            return 0;
        return b;
    }

};

//redo
int minSubArrayLen(int s, vector<int>& nums) {
  if(s <= 0) return 0;
  int n = nums.size(), ans = 0;
  int l = 0, r = 0, sum = 0;
  while(l < n) {
      if(sum < s && r < n) sum += nums[r++];
        else {
              if(sum >= s) ans = ans == 0 ? r-l : min(ans, r-l);
                  sum -= nums[l++];
        }
  }
  return ans;
}

