// review
class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        int i, j;
        unordered_map<string, int> map1;
        unordered_map<string, string> map2;
        vector<string> ans;
        string s1;
        for(string s:strs) {
            s1 = s;
            sort(s1.begin(), s1.end());
            if(map1.find(s1) != map1.end()) {
                if(map1[s1] == 1)
                    ans.push_back(map2[s1]);
                ans.push_back(s);
                map1[s1]++;
            }
            else {
                map1[s1] = 1;
                map2[s1] = s;
            }
        }
        return ans;
    }
};

//redo
class Solution {
public:
    vector<string> anagrams(vector<string>& strs) {
        vector<string> v;
        unordered_map<string, vector<size_t>> m;
        for(size_t i = 0; i < strs.size(); i++) {
            string s = strs[i];
            sort(s.begin(), s.end());
            m[s].push_back(i);
        }
        for(auto &p:m) {
            if(p.second.size() > 1) {
                for(auto i:p.second)
                    v.push_back(strs[i]);
            }
        }
        return v;
    }
};

//redo2
vector<string> anagrams(vector<string>& strs) {
  unordered_map<string, vector<int>> m;
  for(int i = 0; i < strs.size(); i++) {
    string t = strs[i];
    sort(t.begin(), t.end());
    m[t].push_back(i);
  }
  vector<string> ans;
  for(auto &p:m) {
    if(p.second.size() > 1) {
      for(int i:p.second)
        ans.push_back(strs[i]);
    }
  }
  return ans;
}

