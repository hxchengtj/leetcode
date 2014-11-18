// review
struct node {
    int num;
    int a;      // num数目
    node(int x, int y):num(x), a(y) {};
};
class Solution {
public:
    vector<node> v;
    vector<vector<int> > ans;
    vector<int> b;
    vector<vector<int> > permuteUnique(vector<int> &num) {
        sort(num.begin(), num.end());
        v.clear();
        ans.clear();
        b.clear();
        b.resize(num.size());
        if(!num.size())
            return ans;
        int i, j = 1;
        for(i = 1; i < num.size(); i++) {
            if(num[i] == num[i-1])
                j++;
            else {
                node t(num[i-1], j);
                v.push_back(t);
                j = 1;
            }
        }
        node t(num[i-1], j);
        v.push_back(t);
        dfs(0, num.size());
        return ans;
    }
    void dfs(int n, int m) {
        if(n == m) {
            ans.push_back(b);
            return;
        }
        for(int i = 0; i < v.size(); i++) {
            if(v[i].a > 0){
                v[i].a--;
                b[n] = v[i].num;
                dfs(n+1, m);
                v[i].a++;
            }
        }
    }
};