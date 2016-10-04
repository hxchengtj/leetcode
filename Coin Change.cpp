class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        if(n == 0 && amount != 0) return -1;
        vector<pair<int, int>> v;
        vector<int> index(n);
        v.push_back(make_pair(0, 0));
        while(v.back().first < amount) {
            v.push_back(make_pair(v[index[0]].first+coins[0], v[index[0]].second+1));
            for(int i = 1; i < n; i++) 
                if(v.back().first > v[index[i]].first+coins[i]) 
                    v.back() = make_pair(v[index[i]].first+coins[i], v[index[i]].second+1);
                else if(v.back().first == v[index[i]].first+coins[i])
                    v.back().second = min(v.back().second, v[index[i]].second+1);
            for(int i = 0; i < n; i++) 
                if(v.back().first == v[index[i]].first+coins[i]) index[i]++;
        }
        return v.back().first == amount?v.back().second:-1;
    }
};

//version2
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        if(n == 0 || amount < 0) return -1;
        vector<int> f(amount+1, -1);
        f[0] = 0;
        for(int i = 1; i <= amount; i++)
            for(int j = 0; j < n; j++)
                if(i >= coins[j] && f[i-coins[j]] != -1)
                    f[i] = f[i] == -1?f[i-coins[j]]+1:min(f[i], f[i-coins[j]]+1);
        return f[amount];
    }
};
