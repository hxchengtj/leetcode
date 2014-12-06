class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> ans;
        bool flag = false;
        if(!matrix.size() || !matrix[0].size())
            return ans;
        int m = matrix.size(), n = matrix[0].size(), i = 0, j = 0, k = 0, tmp;
        int f[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}, g[4];
        g[0] = n-1;
        g[1] = m-n;
        g[2] = m-1;
        g[3] = 1;
        while(true) {
            switch(k) {
                case 0:  
                case 2: tmp = i+j; break;
                case 1: 
                case 3: tmp = i-j; break;
            }
            if(tmp != g[k]) {
                if(!flag)
                    ans.push_back(matrix[i][j]);
                i += f[k][0];
                j += f[k][1];
                flag = false;
            }
            else if(!flag){
                ans.push_back(matrix[i][j]);
                k = (k+1)%4;
                flag = true;
            }
            else 
                break;
        }
        return ans;
    }
