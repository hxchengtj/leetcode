// review 
// 还是不太会在dfs直接返回vector<vector<int> >类型,只能还是写作全局变量了 囧o(╯□╰)o
class Solution {
public:
    vector<vector<int>> comb;
    vector<int> v;
    vector<vector<int> > combine(int n, int k) {
        comb.clear();
        v.clear();
        dfs(0, n, k);
        return comb;
    }
    void dfs(int b, int n, int k) {
        if(k == 0) {
            comb.push_back(v);
            return;
        }
        for(int i = b+1; i <= n-k+1; i++) {
            v.push_back(i);
            dfs(i, n, k-1);
            v.pop_back();
        }
    }
};
