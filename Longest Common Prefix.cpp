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

//redo
string longestCommonPrefix(vector<string> &strs) {
  if(strs.size() == 0) return "";
  int i, j;
  for(i = 0; i < strs[0].size(); i++)
    for(j = 1; j < strs.size(); j++) {
      if(i >= strs[j].size() || strs[0][i] != strs[j][i]) return strs[0].substr(0, i);
    }
  return strs[0];
}

