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

//version2
class Solution {
public:
    void reverseWords(string &s) {
        reverse(s.begin(), s.end());
        int l = 0, r = 0, k = 0;
        while(l < s.size() && s[l] == ' ') l++;
        while(l < s.size()) {
            r = l;
            while(r < s.size() && s[r] != ' ') r++;
            reverse(s.begin()+l, s.begin()+r);
            copy(s.begin()+l, s.begin()+r, s.begin()+k);
            k += r-l;
            l = r;
            while(l < s.size() && s[l] == ' ') l++;
            if(l < s.size()) s[k++] = ' ';
        }
        s.resize(k);
    }
};