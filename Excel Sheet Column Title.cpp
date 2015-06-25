//review
class Solution {
public:
    string convertToTitle(int n) {
        string s;
        int i;
        while(n) {
            char c = 'A' + ((n-1)%26);
            s = c + s;
            n = (n-1)/26;
        }
        return s;
    }
};