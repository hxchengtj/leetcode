class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s3.length() != s1.length() + s2.length())
            return false;
        int i, j;
        bool f[s3.length()+1][s1.length()+1];
        for(i = 0; i <= s3.length();i++)
            for(j = 0; j <= s1.length(); j++)
                f[i][j] = false;
        f[0][0] = true;
        for(i = 1; i <= s3.length(); i++)
            for(j = 0; j <= i && j <= s1.length(); j++) 
                f[i][j] = (j >= 1 && f[i-1][j-1] && s1[j-1] == s3[i-1]) || ( i-j-1>= 0 && f[i-1][j] && s2[i-j-1] == s3[i-1]);
        for(i = 0; i <= s1.length(); i++)
            if(f[s3.length()][i])
                return true;
        return false;
    }
};