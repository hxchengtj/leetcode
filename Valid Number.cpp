// review
// ><....
class Solution {
public:
    bool isNumber(const char *s) {
        int i;
        bool l = false, r = false;
        i = 0;
        while(s[i] == ' ') 
            i++;
        if(!s[i])
            return false;
        if(s[i] == '-' || s[i] == '+')
            i++;
        while(s[i] >= '0' && s[i] <= '9') {
            l = true;
            i++;
        }
        if(s[i] == '.') {
            i++;
            while(s[i] >= '0' && s[i] <= '9') {
                r = true;
                i++;
            }
            if(!l && !r)
                return false;
            l = true;
            r = false;
        }
        if(s[i] == 'e') {
            i++;
            if(s[i] == '-' || s[i] == '+')
                i++;
            while(s[i] >= '0' && s[i] <= '9') {
                r = true;
                i++;
            }
            if(!l || !r)
                return false;
        }
        while(s[i] == ' ')
            i++;
        if(!s[i])
            return true;
        return false;
    }
};