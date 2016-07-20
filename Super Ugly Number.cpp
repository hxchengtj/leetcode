class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int m = primes.size();
        vector<int> v(n), index(m);
        v[0] = 1;
        for(int i = 1; i < n; i++) {
            v[i] = v[index[0]]*primes[0];
            for(int j = 1; j < m; j++) v[i] = min(v[i], v[index[j]]*primes[j]);
            for(int j = 0; j < m; j++) index[j] += v[i] == v[index[j]]*primes[j]?1:0;
        }
        return v[n-1];
    }
};
