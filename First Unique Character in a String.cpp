class Solution {
public:
    int firstUniqChar(string s) {
        int cnt[26], n = s.size();
        memset(cnt, 0, sizeof(cnt));
        for(int i = 0; i < n; i++) {
            int a = s[i]-'a';
            if(cnt[a] == 0) cnt[a] = i+1;
            else cnt[a] = -1;
        }
        int idx = n;
        for(int i = 0; i < 26; i++) 
            if(cnt[i] > 0)
                idx = min(idx, cnt[i]-1);
        return idx == n?-1:idx;
    }
};
