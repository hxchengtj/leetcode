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

// O(NlogN)
class Solution {
public:
    int _search(vector<int>& f, int a) {
        int l = 0, r = f.size()-1;
        while (l <= r) {
            int m = (l+r)/2;
            if (f[m] < a) l = m+1;
            else r = m-1;
        }
        return l;
    }
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        int n = envelopes.size();
        if(n == 0) return 0;
        //此处的排序很重要，可以处理长宽相等的情况
        sort(envelopes.begin(), envelopes.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.first == b.first? a.second > b.second : a < b;
        });
        vector<int> f(n, INT_MAX);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            auto p = envelopes[i];
            int j = _search(f, p.second);
            ans = max(ans, j+1);
            f[j] = p.second;
        }
        return ans;
    }
};
