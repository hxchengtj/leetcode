class Solution {
public:
    vector<string> ans;
    void dfs(string& num, string s, long long target, int i, long long left, long long last) {
        if(i == num.size()) {
            if(target == left*last) ans.push_back(s);
            return;
        }
        if(last) dfs(num, s+num[i], target, i+1, left, last*10+(num[i]-'0'));
        dfs(num, s+'+'+num[i], target-left*last, i+1, 1, num[i]-'0');
        dfs(num, s+'-'+num[i], target-left*last, i+1, -1, num[i]-'0');
        dfs(num, s+'*'+num[i], target, i+1, left*last, num[i]-'0');
    }
    vector<string> addOperators(string num, int target) {
        ans.clear();
        if(num.size() == 0) return {};
        dfs(num, num.substr(0,1), target, 1, 1, num[0]-'0');
        return ans;
    }
};
