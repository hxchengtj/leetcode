/* review again */
class Solution {
public:
    int longestSubstring(string s, int k) {
        return dfs(s, k, 0, s.size());
    }
    int dfs(string &s, int k, int l, int r) {
        int cnt[26];
        memset(cnt, 0, sizeof(cnt));
        for(int i = l; i < r; i++) cnt[s[i]-'a']++;
        int i = l, max_len = 0;
        while(i < r) {
            while(i < r && cnt[s[i]-'a'] < k) i++;
            if(i == r) break;
            int j = i;
            while(j < r && cnt[s[j]-'a'] >= k) j++;
            if(i == l && j == r) return j-i;
            max_len = max(max_len, dfs(s, k, i, j));
            i = j;
        }
        return max_len;
    }
};
