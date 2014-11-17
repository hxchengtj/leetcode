// review
class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        sort(num.begin(), num.end());
        vector<int> v(3);
        vector<vector<int> > ans;
        int i, j, k, n, t;
        n = num.size();					//unsigned和int区别(0-2:unsigned会溢出)
        for(i = 0; i < n-2; i++) {
            if(i > 0 && num[i] == num[i-1])  //判重
                continue;
            k = n-1;
            j = i+1;
            while(j < k) { 					// two pointers
                t = num[i]+num[j]+num[k];	
                if(t > 0)
                    k--;
                else if (t < 0)
                    j++;
                else  {
                    v[0] = num[i];
                    v[1] = num[j];
                    v[2] = num[k];
                    if ( ans.size() == 0 || num[j] != ans[ans.size()-1][1] || num[k] != ans[ans.size()-1][2])
                        ans.push_back(v);
                    j++;
                    k--;
                }
            } 
        }
        return ans;
    }
};