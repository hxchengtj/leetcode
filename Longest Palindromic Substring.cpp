class Solution {
public:
    string longestPalindrome(string s) {
        string ans = s.substr(0, 1), t;
        int n = s.size();
        for(int i = 0; i < n-1; i++) {
            t = centerpalindrome(s, i, i);
            if(t.size() > ans.size())
                ans = t;
            t = centerpalindrome(s, i, i+1);
            if(t.size() > ans.size())
                ans = t;
        }
        return ans;
    }
    string centerpalindrome(string &s, int a, int b) {
        int l, r;
        for(l = a, r = b; l >= 0 && r < s.length() && s[l] == s[r]; l--, r++);
        l++;
        return s.substr(l, r-l);
    }
};

//version2
class Solution {
public:
    string longestPalindrome(string s) {
        string str("#");
        for(auto c : s) {
            str.push_back(c);
            str.push_back('#');
        }
        
        int n = str.size();
        int f[n];
        memset(f, 0, sizeof(f));
        int m = 0, mx = 0;
        for(int i = 0; i < n; i++) {
            f[i] = i-m < mx ? min(f[2*m-i], mx-i): 1;
            int j = f[i]+i;
            while(j < n && 2*i-j >= 0 && str[j] == str[2*i-j]) j++;
            f[i] = j-i;
            if(j > mx) {
                mx = j;
                m = i;
            }
            
        }
        
        int k = distance(f, max_element(f, f+n));
        string ans;
        for(int i = k-f[k]+1; i < f[k]+k; i++) {
            if(str[i] != '#') ans.push_back(str[i]);
        }
        return ans;
    }
};