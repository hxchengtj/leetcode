//hard
class Solution {
public:
    bool isScramble(string s1, string s2) {
        if(s1.length() != s2.length())
            return false;
        if(s1.length() == 0)
            return true;
        bool f[s1.length()][s2.length()][s1.length()+1];
        int i, j, k, l;
        for(k = 1; k <= s1.length(); k++)
            for(i = 0; i <= s1.length() - k; i++)
                for(j = 0; j <= s2.length() - k; j++) {
                    if(k == 1) {
                        if(s1[i] == s2[j])
                           f[i][j][k] = true;
                        else
                            f[i][j][k] = false;
                    }
                    else {
                        f[i][j][k] = false;
                        for(l = 1; l < k; l++){
                            if(f[i][j][k])
                                break;
                            f[i][j][k] = (f[i][j][l] && f[i+l][j+l][k-l]) || (f[i][j+k-l][l] && f[i+l][j][k-l]);
                        }
                    }
                }
                
        return f[0][0][s1.length()];
        
    }
};
