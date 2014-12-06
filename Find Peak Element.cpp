class Solution {
public:
    int findPeakElement(const vector<int> &num) {
        int n = num.size(), l = 0, r = n-1, m;
        while(l <= r) {
            m = (l+r)/2;
            if(m+1 < n && num[m] < num[m+1])
                l = m+1;
            else
                r = m-1;
        }
        return l;
    }
};
