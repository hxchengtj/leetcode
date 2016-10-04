/* review again */
class Solution {
public:
    int dfs(vector<vector<int>>& matrix, vector<vector<int>>& len, int x, int y, int l) {
        int f[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        int ret = l;
        for(int i = 0; i < 4; i++) {
            int xx = x+f[i][0], yy = y+f[i][1];
            if(xx < matrix.size() && xx >= 0 && yy < matrix[0].size() && yy >= 0 && matrix[xx][yy] > matrix[x][y] && len[xx][yy] < len[x][y]+1) {
                len[xx][yy] = len[x][y]+1;
                ret = max(ret, dfs(matrix, len, xx, yy, l+1));
            }
        }
        return ret;
    }
    bool check_min(vector<vector<int>>& matrix, int x, int y) {
        int f[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        for(int i = 0; i < 4; i++) {
            int xx = x+f[i][0], yy = y+f[i][1];
            if(xx < matrix.size() && xx >= 0 && yy < matrix[0].size() && yy >= 0 && matrix[xx][yy] < matrix[x][y]) return false;
        }
        return true;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if(m == 0) return 0;
        int n =  matrix[0].size();
        if(n == 0) return 0;
        vector<vector<int>> len(m, vector<int>(n, 1));
        int ans = 0;
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++) 
                if (check_min(matrix, i, j)) ans = max(ans, dfs(matrix, len, i, j, 1));
        return ans;
    }
};

//version2
class Solution {
public:
    int dfs(vector<vector<int>>& matrix, int x, int y, vector<vector<int>>& cache) {
        if(cache[x][y]) return cache[x][y];
        int f[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int maxL = 1;
        for(int i = 0; i < 4; i++) {
            int xx = x + f[i][0], yy = y + f[i][1];
            if(xx >= 0 && xx < matrix.size() && yy >= 0 && yy < matrix[0].size() && matrix[xx][yy] > matrix[x][y]) {
                maxL = max(maxL, dfs(matrix, xx, yy, cache)+1);
            }
        }
        cache[x][y] = maxL;
        return maxL;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0) return 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> cache(m, vector<int>(n));
        int ans = 0;
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++) {
                ans = max(ans, dfs(matrix, i, j, cache));
            }
        return ans;
    }
};
