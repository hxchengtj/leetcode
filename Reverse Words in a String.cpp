class Solution {
public:
    void reverseWords(string &s) {
        int i,j;
        vector<string> v;
        string t, a;
        for(i = 0; i < s.length(); i++) {
            if(s[i] == ' ') {
                if(t.length() > 0) { 
                    if(a.length())
                        a = t + " "+ a;
                    else 
                        a = t;
                }
                t = "";
            }
            else
                t += s[i];
        }
        if(t.length() > 0){ 
            if(a.length())
                a = t + " "+ a;
            else 
                a = t;
        }
        s = a;
    }
};
