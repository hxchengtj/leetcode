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