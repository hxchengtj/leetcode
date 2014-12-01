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
