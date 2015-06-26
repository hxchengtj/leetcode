class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string s = "";
        if(numerator < 0 && denominator > 0 || numerator > 0 && denominator < 0)
            s.append("-");
        long long n = numerator, d = denominator, r;
        n = abs(n);
        d = abs(d);
        r = n%d;
        char c[100];
        sprintf(c, "%lld", (n/d));
        s.append(c);
        if (r)
            s.append(".");
        else
            return s;
        unordered_map<int, int> m;
        while(m.find(r) == m.end() && r != 0) {
            m.insert(make_pair(r, s.size()));
            r *= 10;
            memset(c, 0, 100*sizeof(char));
            sprintf(c, "%lld", (r/d));
            s.append(c);
            r = r%d;
        }
        if(r != 0) {
            s.insert(m[r], "(");
            s.append(")");
        }
        return s;
    }
};