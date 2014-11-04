class Solution {
public:
    int romanToInt(string s) {
        int t[26] = {0, 0, 100, 500, 0, 0, 0, 0, 1, 0, 0, 50, 1000, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 10, 0, 0};
        int ans = 0, i, j, k;
        for(i = 0; i < s.length() - 1; i++) {
            j = s[i] - 'A';
            k = s[i+1] - 'A';
            if(t[j] < t[k])
                ans -= t[j];
            else
                ans += t[j];
        }
        j = s[i] - 'A';
        ans += t[j];
        return ans;
    }
};
