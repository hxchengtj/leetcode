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

//version2
//redo
string longestPalindromic(string s) {
  string str = "#";
  for(auto c:s) {
    str.push_back(c);
    str.push_back('#');
  }
  int n = str.size();
  vector<int> f(n, 0);
  int i = 0, j = 1;
  while(j < n) {
    if(i + f[i] < j || f[2*i-j]+j == i+f[i]) {
      int k = i + f[i] + 1;
      while(k < n && 2*j-k >= 0 && str[k] == str[2*j-k]) k++;
      f[j] = k-j-1;
      i = j;
    }
    else f[j] = min(f[2*i-j], i+f[i]-j);
    j++;
  }
  i = distance(f.begin(), max_element(f.begin(), f.end()));
  string ans;
  for(j = i-f[i]; j <= i+f[i]; j++)
    if(str[j] != '#') ans.push_back(str[j]);
  return ans;
}

