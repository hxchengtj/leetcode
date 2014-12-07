class Solution {
public:
    string convert(string s, int nRows) {
        string ans;
        int i, j, k;
        int f[2];
        if(nRows <= 1)
            return s;
        for(i = 0; i < nRows; i++) {
             f[0] = 2*(nRows-i-1);
             f[1] = 2*i;
             j = i;
             k = 0;
             while(j < s.length()) {
                 ans += s[j];
                 if(f[k] == 0)
                    k = (k+1)%2;
                j += f[k];
                k = (k+1)%2;
             }
        }
        return ans;
    }
};