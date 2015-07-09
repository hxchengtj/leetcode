// hard
// review
class Solution {
public:
    vector<int> grayCode(int n) {  
        vector<int> ans;
        int i, j = 0;
        for(i = 0; i < (1<<n); i++) {
            j ^= (i & (-i));
            ans.push_back(j);
        }
        return ans;
    }
};


//version2
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans;
        ans.push_back(0);
        for(int i = 0; i < n; i++) {
            for(int j = (int)ans.size()-1; j >= 0; j--)
                ans.push_back(ans[j] | (1<<i));
        }
        return ans;
    }
};