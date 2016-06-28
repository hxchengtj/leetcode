// review !!!
class Solution {
public:
    bool isSelfCrossing(vector<int>& x) {
        int n = x.size(),i, j;
        for(i = 2; i < n && x[i] > x[i-2]; i++);
        if (i < n && i >= 3 && x[i] >= (x[i-2] - (i>=4?x[i-4]:0))) x[i-1] -= x[i-3];
        for(i++; i < n && x[i] < x[i-2]; i++);
        return i < n;
    }
};
