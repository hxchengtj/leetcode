//review
class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        int i, j, k, t, ans = 0, b = INT_MAX;
        for(i = 0; i < num.size(); i++) {
            t = target - num[i];
            k = num.size()-1;
            for(j = i+1; j < k; j++) {
                while(num[k] + num[j] > t && k > j) {
                    if(num[k]+num[j]-t < b) {
                        ans = num[k]+num[j]+num[i];
                        b = num[k]+num[j]-t;
                    }
                    k--;
                }
                if(k > j && abs(num[k]+num[j]-t) < b) {
                    ans = num[k]+num[j]+num[i];
                    b = abs(num[k]+num[j]-t);
                }
            }
        }
        return ans;
    }
};