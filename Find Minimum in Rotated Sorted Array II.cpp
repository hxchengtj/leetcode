// review
class Solution {
public:
    int findMin(vector<int> &num) {
        int l = 0, r = num.size()-1, m;
        while(l <= r && num[l] >= num[r]) {
            m = (l+r) / 2;
            if(num[l] > num[m])
                r = m;
            else if(num[r] < num[m])
                l = m+1;
            else
                r = r-1;
        }
        return num[l];
    }
};