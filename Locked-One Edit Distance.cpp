class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int m = s.size(), n = t.size();
        if(abs(m-n) > 1) return false;
        int i = 0, j = 0, cnt = 0;
        while(i < m || j < n) {
            if(i == m || j == n || s[i] != t[j]) {
                cnt++;
                if(m < n) j++;
                else if(m > n) i++;
                else {
                    i++; j++;
                }
            }
            else {
                i++; j++;
            }
            if(cnt > 1) return false;
        }
        return cnt == 1;
    }
};
