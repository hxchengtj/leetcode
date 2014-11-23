// hard
// review
class Solution {
public:
    vector<int> grayCode(int n) {  
        vector<int> ans;
        int i, j = 0;
        for(i = 0; i < (1<<n); i++) {
            j ^= (i & (-i));
            ans.push_back(j);
        }
        return ans;
    }
};
//backtracking
/*
class Solution {
public:
    vector<int> ans;
    vector<bool> f;
    int a;
    vector<int> grayCode(int n) {  
        f.resize(1<<n);
        a = 0;
        f[0] = true;
        ans.push_back(0);
        dfs(1<<n, n);
        return ans;
    }
    void dfs(int k, int n) {
        if(k  <= 1)
            return;
        for(int i = 0; i < n; i++) {
            a ^= (1 << i);
            if(!f[a]) {
                ans.push_back(a);
                f[a] = true;
                dfs(k-1, n);
                return;
            }
            a ^= (1 << i);
        }
    }
    
};
*/