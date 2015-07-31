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


//version2
//redo
string shortestPalindrome(string s) {
  string str = "#";
  for(char c:s) {
    str.push_back(c);
    str.push_back('#');
  }
  int n = str.size();
  int f[n];
  f[0] = 0;
  int i = 0, j;
  for(j = 1; j < n; j++){
    if(f[i]+i < j || f[i]+i == f[2*i-j]+j) {
      int k = f[i]+i;
      while(k < n && 2*j-k >= 0 && str[k] == str[2*j-k]) k++;
      f[j] = k-j-1;
      i = j;
    }
    else f[j] = min(f[i]+i-j, f[2*i-j]);
  }
  for(j = n-1; j >= 0 && f[j] != j; j--) ;
  string ans;
  for(i = n-1; i > f[j]+j; i--)
    if(str[i] != '#') ans.push_back(str[i]);
  ans.append(s);
  return ans;
}

