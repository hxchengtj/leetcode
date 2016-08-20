class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        if(matrix.size() == 0 || matrix[0].size() == 0) return -1;
        int m = matrix.size(), n = matrix[0].size();
        vector<tuple<int, int, int>> v(m);
        for(int i = 0; i < m; i++) v[i] = make_tuple(matrix[i][0], i, 0);
        make_heap(v.begin(), v.end(), greater<tuple<int, int, int>>());
        int ans = 0;
        for(int i = 0; i < k; i++) {
            auto p = v[0];
            ans = get<0>(p);
            pop_heap(v.begin(), v.end(), greater<tuple<int, int, int>>());
            if(get<2>(p)+1 < n) {
                v.back() = make_tuple(matrix[get<1>(p)][get<2>(p)+1], get<1>(p), get<2>(p)+1);
                push_heap(v.begin(), v.end(), greater<tuple<int, int, int>>());
            } else v.pop_back();
        }
        return ans;
    }
};
