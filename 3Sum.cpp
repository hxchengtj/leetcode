// review
class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        sort(num.begin(), num.end());
        vector<int> v(3);
        vector<vector<int> > ans;
        int i, j, k, n, t;
        n = num.size();					//unsigned和int区别(0-2:unsigned会溢出)
        for(i = 0; i < n-2; i++) {
            if(i > 0 && num[i] == num[i-1])  //判重
                continue;
            k = n-1;
            j = i+1;
            while(j < k) { 					// two pointers
                t = num[i]+num[j]+num[k];
                if(t > 0)
                    k--;
                else if (t < 0)
                    j++;
                else  {
                    v[0] = num[i];
                    v[1] = num[j];
                    v[2] = num[k];
                    if ( ans.size() == 0 || num[j] != ans[ans.size()-1][1] || num[k] != ans[ans.size()-1][2])
                        ans.push_back(v);
                    j++;
                    k--;
                }
            }
        }
        return ans;
    }

    //redo
    //version2
    class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        if(nums.size() < 3)
            return ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> v(3, 0);
        for(int i = 0; i < n-2; i++) {
            int j = i+1, k = n-1;
            while(j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if(sum < 0) {
                    j++;
                    while(j < k && nums[j] == nums[j-1]) j++;
                }
                else if(sum > 0) {
                    k--;
                    while(j < k && nums[k] == nums[k+1]) k--;
                }
                else {
                    v[0] = nums[i]; v[1] = nums[j]; v[2] = nums[k];
                    ans.push_back(v);
                    j++;
                    while(j < k && nums[j] == nums[j-1]) j++;
                    k--;
                    while(j < k && nums[k] == nums[k+1]) k--;
                }
            }
            i++;
            while(i < n-2 && nums[i] == nums[i-1]) i++;
            i--;
        }
    }
};
};

//redo
vector<vector<int>> threeSum(vector<int>& nums) {
  sort(nums.begin(), nums.end());
  vector<vector<int>> ans;
  int n = nums.size();
  for(int i = 0; i < n-2; i++) {
    if(i > 0 && nums[i] == nums[i-1]) continue;
    int j = i+1, k = n-1;
    while(j < k) {
      if(j > i+1 && nums[j] == nums[j-1]) j++;
      else if(k < n-1 && nums[k] == nums[k+1]) k--;
      else if(nums[i]+nums[j]+nums[k] < 0) j++;
      else if(nums[i]+nums[j]+nums[k] > 0) k--;
      else {
        ans.push_back({nums[i], nums[j], nums[k]});
        j++; k--;
      }
    }
  }
  return ans;
}

