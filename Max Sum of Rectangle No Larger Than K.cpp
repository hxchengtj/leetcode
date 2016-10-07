/* review again */
class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        if(m == 0) return 0;
        int n = matrix[0].size();
        if(n == 0) return 0;
        int ans = INT_MIN;
        for(int i = 0; i < n; i++) {
            vector<int> sum(m);
            for(int j = i; j < n; j++) {
                for(int l = 0; l < m; l++) sum[l] += matrix[l][j];
                set<int> s;
                int cursum = 0;
                for(int l = 0; l < m; l++) {
                    s.insert(cursum);
                    cursum += sum[l];
                    auto iter = s.lower_bound(cursum-k);
                    if(iter != s.end()) ans = max(ans, cursum-*iter);
                }
            }
        }
        return ans;
    }
};
