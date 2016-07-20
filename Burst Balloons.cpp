class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        int f[n+2][n+2];
        memset(f, 0, sizeof(f));
        vector<int> g(n+2);
        g[0] = 1; g[n+1] = 1;
        for(int i = 0; i < n; i++) g[i+1] = nums[i];
        for(int i = 2; i <= n+1; i++)
            for(int j = 0; j <= n+1-i; j++) 
                for(int k = j+1; k < j+i; k++)
                f[j][j+i] = max(f[j][j+i], f[j][k]+f[k][j+i]+g[j]*g[k]*g[j+i]);
        return f[0][n+1];
    }
};
