class Solution {
public:
    vector<string> v;
    vector<vector<string> > ans;
    vector<vector<string>> partition(string s) {
        dfs(0, s);
        return ans;
    }
    void dfs(int x, string &s) {
        if(x >= s.length()) {
            ans.push_back(v);
            return;
        }
        for(int i = x; i < s.size(); i++) {
            int l = x;
            int r = i;
            while(l < r) {
                if(s[l] != s[r])
                    break;
                l++;
                r--;
            }
            if(l >= r) {
                v.push_back(s.substr(x, i-x+1));
                dfs(i+1, s);
                v.pop_back();
            }
        }
    }
};