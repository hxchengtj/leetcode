// review
class Solution {
public:
    int maxArea(vector<int> &height) {
        int n = height.size(), l = 0, r = n-1, ans = 0;
        while(l < r) {
            if(height[l] < height[r]) {
                ans = max(ans, height[l] * (r-l));
                l++;
            }
            else {
                ans = max(ans, height[r] * (r-l));
                r--;
            }
        }
        return ans;
    }
};


//redo
int maxArea(vector<int>& height) {
  int l = 0, r = height.size()-1;
  int ans = 0;
  while(l < r){
    if(height[l] < height[r]) {
      ans = max(ans, height[l]*(r-l));
      l++;
    }
    else {
      ans = max(ans, height[r]*(r-l));
      r--;
    }
  }
  return ans;
}

