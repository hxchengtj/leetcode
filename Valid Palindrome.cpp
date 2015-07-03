class Solution {
public:
    bool isPalindrome(string s) {
        bool ans = true;
        int i = 0, j;
        for(i = 0; i < s.size(); i++) {
            if(s[i] >= 'A' && s[i] <= 'Z')
                s[i] = s[i] - 'A' + 'a';
            if( (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9') )
                continue;
            s.erase(i, 1);
            i--;
        }
        i = 0;
        j = s.size()-1;
        while(i <= j && ans) {
            if(s[i] != s[j])
                ans = false;
            i++;
            j--;
        }
        return ans;
    }
};

//redo 
//version2
class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0, r = s.size()-1;
        while(l < r) {
            if(!isalnum(s[l])) l++;
            else if(!isalnum(s[r])) r--;
            else if(tolower(s[l]) != tolower(s[r])) return false;
            else {
                l++;
                r--;
            }
        }
        return true;
    }
};