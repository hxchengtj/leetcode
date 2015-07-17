class Solution {
public:
    string shortestPalindrome(string s) {
        string a = s, b;
        reverse(a.begin(), a.end());
        for(int i = s.size(); i > 0; i--) {
            if(s.substr(0, i) == a.substr(a.size()-i, i)) {
                b = a.substr(0, a.size()-i) + s;
                return b;
            }
        }
        return b;
    }
};

//version2
class Solution {
public:
    string shortestPalindrome(string s) {
        string str = "#";
        for(auto c:s) {
            str.push_back(c);
            str.push_back('#');
        }
        int n = str.size();
        int f[n];
        memset(f, 0, sizeof(f));
        
        int m = 0,  mx = 0;
        for(int i = 0; i < n; i++) {
            f[i] = i < mx ? min(f[2*m-i], mx-i) : 1;
            int j = i+f[i];
            while(j < n && 2*i-j >= 0 && str[j] == str[2*i-j]) j++;
            f[i] = j-i;
            if(j > mx) {
                mx = j;
                m = i;
            }
        }
        
        int i = n-1;
        while(i >= 0 && i-f[i]+1 != 0) i--;
        
        string ans;
        for(int j = n-1; j >= 0 && j >= i+f[i]; j--)
            if(str[j] != '#') ans.push_back(str[j]);
        ans.append(s);
        return ans;
        
    }
};