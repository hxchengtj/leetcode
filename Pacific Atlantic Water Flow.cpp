class Solution {
public:
    void dfs(vector<vector<int>>& matrix, int x, int y, vector<vector<bool>>& canFlow) {
        int m = matrix.size(), n = matrix[0].size();
        int f[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        canFlow[x][y] = true;
        for(int i = 0; i < 4; i++) {
            int xx = x + f[i][0], yy = y + f[i][1];
            if(xx >= 0 && xx < m && yy >= 0 && yy < n && !canFlow[xx][yy] && matrix[xx][yy] >= matrix[x][y]) {
                dfs(matrix, xx, yy, canFlow);
            }
        }
    }
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0)
            return {};
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<bool>> canFlowP(m, vector<bool>(n)), canFlowA(m, vector<bool>(n));
        for(int i = 0; i < n; i++)
            dfs(matrix, 0, i, canFlowP);
        for(int i = 0; i < m; i++)
            dfs(matrix, i, 0, canFlowP);
        
        for(int i = 0; i < n; i++)
            dfs(matrix, m-1, i, canFlowA);
        for(int i = 0; i < m; i++)
            dfs(matrix, i, n-1, canFlowA);
        
        vector<pair<int, int>> ans;
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(canFlowP[i][j] && canFlowA[i][j])
                    ans.push_back(make_pair(i, j));
        return ans;
    }
};
