class Solution {
public:
    string countAndSay(int n) {
        string s1("1"), s2("1");
        int i, j, k;
        char c;
        for(i = 0; i < n-1; i++) {
            s1 = s2;
            s2 = "";
            k = 1;
            for(j = 1; j < s1.length(); j++) {
                if(s1[j] == s1[j-1]) 
                    k++;
                else {
                    c = k + '0';
                    s2 = s2 + c + s1[j-1];
                    k = 1;
                }
            }   
            c = k + '0';
            s2 = s2 + c + s1[j-1];
        }
        return s2;
    }
    
};
