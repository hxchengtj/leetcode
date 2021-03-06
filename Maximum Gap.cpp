/* review again */
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        queue<int> q[10];
        int a = 1, b, n = nums.size();
        if(n <= 1)
            return 0;
        int maxn = nums[0];
        for(int i = 1; i < n; i++)
            maxn = max(maxn, nums[i]);
        while(a <= maxn) {
            for(int i = 0; i < n; i++) {
                b = (nums[i]/a)%10;
                q[b].push(nums[i]);
            }
            int j = 0;
            for(int i = 0;i < 10; i++) {
                while(!q[i].empty()) {
                    nums[j] = q[i].front();
                    j++;
                    q[i].pop();
                }
            }
            a *= 10;
        }
        int maxgap = 0;
        for(int i = 1; i < n; i++)
            maxgap = max(maxgap, nums[i]-nums[i-1]);
        return maxgap;
    }
};


//version2
//review
//review
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) return 0;

        int minnum = *min_element(nums.begin(), nums.end());
        int maxnum = *max_element(nums.begin(), nums.end());
        int D = max((maxnum-minnum+n-2)/(n-1), 1);
        int mins[n], maxs[n];
        fill(mins, mins+n, maxnum);
        fill(maxs, maxs+n, -1);
        for(auto num:nums) {
            int t = (num-minnum)/D;
            mins[t] = min(num, mins[t]);
            maxs[t] = max(num, maxs[t]);
        }

        int ans = 0;
        int l = 0;
        for(int i = 0; i < n; i++)
            if(maxs[i] != -1) {
                ans = max(mins[i]-maxs[l], ans);
                l = i;
            }
        return ans;
    }
};

//version2
//redo
int maximumGap(vector<int>& nums) {
  if(nums.size() <= 1) return 0;
  int n = nums.size();
  int minnum = *min_element(nums.begin(), nums.end());
  int maxnum = *max_element(nums.begin(), nums.end());
  int T = max((maxnum-minnum+n-2)/(n-1), 1);
  //此处应该用n, 如果maxnum-minnum可以被n-1整除,则maxnum被切分在mins[n-1]和maxs[n-1]
  vector<int> mins(n, 0), maxs(n, -1);
  for(auto a:nums) {
    int b = (a-minnum)/T;
    if(mins[b] > maxs[b]) mins[b] = maxs[b] = a;
    else {
      mins[b] = min(mins[b], a);
      maxs[b] = max(maxs[b], a);
    }
  }
  int ans = 0, maxe = minnum;
  for(int i = 0; i < n; i++) {
    if(mins[i] <= maxs[i]) {
      ans = max(ans, mins[i]-maxe);
      maxe = maxs[i];
    }
  }
  return ans;
}

