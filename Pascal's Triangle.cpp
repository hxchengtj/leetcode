class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > ans;
        vector<int> v;
        int i, j, k;
        for(i = 1; i <= numRows; i++) {
            k = 1;
            for(j = 1; j < i - 1; j++) {
                v[j] = v[j]+k;
                k = v[j]-k;
            }
            v.push_back(1);
            ans.push_back(v);
        }
        return ans;
    }
};
