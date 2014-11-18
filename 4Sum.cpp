class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        int i, j, k, l, n = num.size(), t;
        vector<vector<int> > ans;
        vector<int> v(4);
        for(i = 0; i < n-3; i++) {
            if(i > 0 && num[i] == num[i-1])
                continue;
            for(j = i+1; j < n-2; j++) {
                if(j >i+1 && num[j] == num[j-1])
                    continue;
                k = j+1;
                l = n-1;
                while(k < l) {
                    t = num[i] + num[j] + num[k] + num[l];
                    if(t < target)
                        k++;
                    else if(t > target)
                        l--;
                    else {
                        v[0] = num[i];
                        v[1] = num[j];
                        v[2] = num[k];
                        v[3] = num[l];
                        if(ans.size() == 0 || ans.back()[0] != num[i] || ans.back()[1] != num[j] || ans.back()[2] != num[k])
                            ans.push_back(v);
                        k++;
                        l--;
                    }
                }
            }
        }
        return ans;
    }
};