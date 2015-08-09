//review
class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        int i, j, k, t, ans = 0, b = INT_MAX;
        for(i = 0; i < num.size(); i++) {
            t = target - num[i];
            k = num.size()-1;
            for(j = i+1; j < k; j++) {
                while(num[k] + num[j] > t && k > j) {
                    if(num[k]+num[j]-t < b) {
                        ans = num[k]+num[j]+num[i];
                        b = num[k]+num[j]-t;
                    }
                    k--;
                }
                if(k > j && abs(num[k]+num[j]-t) < b) {
                    ans = num[k]+num[j]+num[i];
                    b = abs(num[k]+num[j]-t);
                }
            }
        }
        return ans;
    }
};

//redo
//version2
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.size() < 3)
            return 0;
        sort(nums.begin(), nums.end());
        int ans = nums[0]+nums[1]+nums[2], n = nums.size();
        for(int i = 0; i < n-2; i++) {
            int j = i+1, k = n-1;
            while(j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if(sum < target) {
                    if(abs(target-ans) > abs(target-sum))
                        ans = sum;
                    j++;
                }
                else if(sum > target) {
                    if(abs(target-ans) > abs(target-sum))
                        ans = sum;
                    k--;
                }
                else return sum;
            }
        }
        return ans;
    }
};

//redo
int threeSumClosest(vector<int>& nums, int target) {
  sort(nums.begin(), nums.end());
  int n = nums.size(), ans = 0;
  bool flag = false;
  for(int i = 0; i < n-2; i++) {
    if(i > 0 && nums[i] == nums[i-1]) continue;
    int j = i+1, k = n-1;
    while(j < k) {
      int sum = nums[i]+nums[j]+nums[k];
      if(j > i+1 && nums[j] == nums[j-1]) j++;
      else if(k < n-1 && nums[k] == nums[k+1]) k--;
      else if(sum == target) return sum;
      else if(sum < target) {
        if(!flag || abs(ans-target) > abs(target-sum)) {
          flag = true;
          ans = sum;
        }
        j++;
      }
      else {
        if(!flag || abs(ans-target) > abs(sum-target)) {
          flag = true;
          ans = sum;
        }
        k--;
      }
    }
  }
  return ans;
}

