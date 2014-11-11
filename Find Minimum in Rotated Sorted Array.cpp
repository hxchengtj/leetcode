class Solution {
public:
    int findMin(vector<int> &num) {
        int l = 0, r = num.size()-1, mid, ans = INT_MAX;
        while (l <= r) {
            mid = (l+r)/2;
            ans = min(ans, num[l]);
            if(num[l] <= num[mid])
                l = mid+1;
            else
                r = mid;
        }
        return ans;
    }
};