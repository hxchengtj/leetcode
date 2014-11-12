class Solution {
public:
    string getPermutation(int n, int k) {
        int a[n+1], i, j, l, m;
        vector<bool> b(n+1);
        string s;
        a[0] = 1;
        k--;
        for(i = 1; i <= n; i++)
            a[i] = i * a[i-1];
        for(i = n-1; i >= 0; i--) {
            l = k/a[i];
            m = 0;
            for(j = 1; j <= n; j++)
                if(!b[j]) {
                    if(l == m) {
                        s += (j+'0');
                        b[j] = true;
                        break;
                    }
                    m++;
                }
            k = k%a[i];
        }
        return s;
    }
};