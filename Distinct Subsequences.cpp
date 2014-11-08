// hard
class Solution {
public:
    int numDistinct(string S, string T) {
        int f[T.length()][S.length()];
        int i, j, k;
        if(!S.length() || !T.length())
            return 0;
        for(i = 0; i < T.length(); i++)
            for(j = 0; j < S.length(); j++)
                f[i][j] = 0;
        if(S[0] == T[0])
            f[0][0] = 1;
        for( j = 1; j < S.length(); j++)
            if(S[j] == T[0])
                f[0][j] = f[0][j-1]+1;
            else
                f[0][j] = f[0][j-1];
        for( i = 1; i < T.length(); i++)
            for( j = i; j < S.length(); j++) 
                if(T[i] == S[j]) 
                    f[i][j] = f[i-1][j-1] + f[i][j-1];
                else
                    f[i][j] = f[i][j-1];
                    
        return f[T.length()-1][S.length()-1];
    }
};
