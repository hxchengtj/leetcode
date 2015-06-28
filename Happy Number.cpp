class Solution {
public:
    int cal_n(int n) {
        int m = 0, a;
        while(n != 0) {
            a = n%10;
            m += a*a;
            n = n/10;
        }
        return m;
    }
    bool isHappy(int n) {
        unordered_map<int, int> m;
        while(n != 1) {
            if(m.find(n) != m.end())
                return false;
            m.insert(make_pair(n, 0));
            n = cal_n(n);
        }
        return true;
    }
};