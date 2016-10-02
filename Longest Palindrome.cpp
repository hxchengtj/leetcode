class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> cntL(26), cntU(26);
        for(char c:s) {
            if(c >= 'a' && c <= 'z')
                cntL[c-'a']++;
            else cntU[c-'A']++;
        }
        int maxOdd = 0, ans = 0;
        for(int i = 0; i < 26; i++) {
            if(cntL[i]&1) 
                maxOdd = max(maxOdd, 1);
            ans += cntL[i]/2*2;
            
            if(cntU[i]&1) 
                maxOdd = max(maxOdd, 1);
            ans += cntU[i]/2*2;
        }
        ans += maxOdd;
        return ans;
    }
};
