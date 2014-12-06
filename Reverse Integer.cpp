// ><...
class Solution {
public:
    int reverse(int x) {
        if(x == INT_MIN)
            return 0;
        vector<int> v, v2;
        int a = INT_MAX;
        bool b = (x < 0), o;
        if(b)
            x = -x;
        while(x) {
            v.push_back(x%10);
            v2.push_back(a%10);
            x = x/10;
            a = a/10;
        }
        int n = v.size(), i, ans = 0;
        o = (a == 0);
        for(i = 0; i < n; i++) {
            if(o) {
                if(v[i] < v2[n-1-i])
                    o = false;
                else if(v[i] > v2[n-1-i])
                    return 0;
            }
            ans = ans*10+v[i];
        }
        if(b) {
            if(ans == INT_MAX)
                return 0;
            ans = -ans;
        }
        return ans;
    }
};
