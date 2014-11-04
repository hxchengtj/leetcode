// review 
// 还是不太会在dfs直接返回vector<vector<int> >类型,只能还是写作全局变量了 囧o(╯□╰)o
class Solution {
public:
    vector<vector<int> > order;
    vector<int> v;
    vector<vector<int> > combine(int n, int k) {
        order.clear();
        v.clear();
        if(n < k)
            return order; 
        p = new bool [n+1];
        int i;
        for(i = 0; i <= n; i++)
            p[i] = false;
        dfs(n, k);
        delete p;
        return order;
    }
    void dfs(int n, int k) {
        if(k == 0) {
            order.push_back(v);
            return;
        }
        for(int i = 1; i <= n; i++) {
            if(!p[i]) {
                p[i] = true;
                v.push_back(i);
                dfs(n, k-1);
                v.pop_back();
                p[i] = false;
            }

        }
    }
};
