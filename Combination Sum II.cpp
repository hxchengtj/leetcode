class Solution {
public:
    vector<vector<int> > ans;
    vector<int> v;
    vector<int> s;
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        ans.clear();
        v.clear();
        s.clear();
        v.resize(num.size());
        s.resize(num.size());
        if(num.size() > 0) {
            s[num.size()-1] = 1;
            for(int i = num.size() - 2; i >= 0; i--)  //避免重复计算
                if(num[i] == num[i+1])
                    s[i] = s[i+1] + 1;
                else 
                    s[i] = 1;
            dfs(0, 0, num, target);
        }
        return ans;
    }
    void dfs(int a, int now, vector<int> &num, int target) {
        if(target == 0) {
            vector<int> p(v.begin(), v.begin()+now);
            ans.push_back(p);
            return;
        }
        if(a >= num.size() || num[a] > target)
            return;
        for(int i = 0; i <= min(s[a], target/num[a]); i++) {
            if(i > 0) 
                v[now+i-1] = num[a];
            dfs(a+s[a], now+i, num, target-num[a]*i);
        }
    }
};
