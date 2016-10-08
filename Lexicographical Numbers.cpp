class Solution {
public:
    vector<int> lexicalOrder(int n) {
        if(n <= 0) return {};
        vector<int> ans;
        dfs(ans, n, 0);
        return ans;
    }
    void dfs(vector<int>& ans, int n, int a) {
        if(a >= 1 && a <= n) {
            ans.push_back(a);
        }
        if(a > n/10) return;
        for(int i = a == 0?1:0; i <= min(n-10*a, 9); i++) 
            dfs(ans, n, 10*a+i);
    }
};
