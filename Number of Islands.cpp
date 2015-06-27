class Solution {
public:
    vector<vector<bool>> v;
    int r = 0;
    int numIslands(vector<vector<char>>& grid) {
        v.clear();
        r = 0;
        if(grid.size() == 0 || grid[0].size() == 0)
            return 0;
        int m = grid.size(), n = grid[0].size();
        v.resize(m);
        for(int i = 0; i < m; i++)
            v[i].resize(n);
        for(int i = 0; i < m; i++) 
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == '1' && v[i][j] == false) {
                    dfs(grid, i, j, m, n);
                    r++;
                }
            }
        return r;
    }
    void dfs(vector<vector<char>>& grid, int x, int y, int m, int n) {
        if(x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == '0' || v[x][y] == true)
            return;
        v[x][y] = true;
        dfs(grid, x-1, y, m, n);
        dfs(grid, x+1, y, m, n);
        dfs(grid, x, y-1, m, n);
        dfs(grid, x, y+1, m, n);
    }
};