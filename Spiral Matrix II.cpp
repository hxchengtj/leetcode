class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > ans(n, vector<int>(n));
        if(n == 0)
            return ans;
        int i = 0, j = 0, k = 0, t = 1, x = 0;
        int f[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}, g[4];
        g[0] = n-1;
        g[1] = 0;
        g[2] = n-1;
        g[3] = 1;
        bool flag = false;
        while(t <= n*n) {
            switch(k) {
                case 0: 
                case 2: x = i+j; break;
                case 1:
                case 3: x = i-j; break;
            }
            if(x != g[k]) {
                if(!flag) {
                    ans[i][j] = t;
                    t++;
                }
                i += f[k][0];
                j += f[k][1];
                flag = false;
            }
            else if(flag)
                return ans;
            else {
                ans[i][j] = t;
                t++;
                flag = true;
                k = (k+1)%4;
            }
        }
        return ans;
    }
};
