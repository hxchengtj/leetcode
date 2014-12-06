// 写错了不知为何过了=。=
/*
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
*/

class Solution {
public:
    int findPeakElement(const vector<int> &num) {
        int n = num.size(), l = 0, r = n-1, m;
        while(l <= r) {
            m = (l+r)/2;
            if(m+1 < n && num[m] < num[m+1])
                l = m+1;
            else if(m-1 >= 0 && num[m] < num[m-1])
                r = m-1;
            else 
                return m;
        }
        return l;
    }
};
