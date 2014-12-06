class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        string ans;
        if(!strs.size())
            return ans;
        ans = strs[0];
        int i, j;
        for(i = 1; i < strs.size(); i++) { 
            for(j = 0; j < ans.size() && j < strs[i].size() && ans[j] == strs[i][j]; j++) 
                ;
            ans.resize(j);
        }
        return ans;
    }
    
};
