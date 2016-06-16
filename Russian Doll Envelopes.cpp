// O(n^2)
class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end());
        int n = envelopes.size();
        if (n == 0) return 0;
        vector<int> f(n, 1);
        int ans = 1;
        for(int i = 1; i < n; i++) {
            for(int j = i-1; j >= 0; j--) {
                if (envelopes[i].first > envelopes[j].first && envelopes[i].second > envelopes[j].second)
                    f[i] = max(f[i], f[j]+1);
            }
            ans = max(ans, f[i]);
        }
        return ans;
    }
};
