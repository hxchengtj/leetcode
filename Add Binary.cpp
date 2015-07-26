class Solution {
public:
    string addBinary(string a, string b) {
        int i, j, n = a.length(), m = b.length(), x, y, z;
        string s;
        char c;
        z = 0;
        for(i = n-1, j = m-1; i >= 0 && j>= 0; i--, j--) {
            x = a[i]-'0';
            y = b[j]-'0';
            z += x+y;
            c = (z%2)+'0';
            s = c+s;
            z = z/2;
        }
        while(i >= 0) {
            z += a[i]-'0';
            c = (z%2)+'0';
            s = c+s;
            z = z/2;
            i--;
        }
        while(j >= 0) {
            z += b[j]-'0';
            c = (z%2)+'0';
            s = c+s;
            z = z/2;
            j--;
        }
        if(z)
            s = '1'+s;
        return s;
    }
};


//redo
class Solution {
public:
    string addBinary(string a, string b) {
        string s;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        size_t i = 0, j = 0, r = 0;
        while(i < a.size() || j < b.size() || r) {
            if(i < a.size()) r += a[i++] - '0';
            if(j < b.size()) r += b[j++] - '0';
            s.push_back((r&1)+'0');
            r = r >> 1;
        }
        reverse(s.begin(), s.end());
        return s;
    }
};


//redo2
string addBinary(string a, string b) {
  int i = a.size()-1, j = b.size()-1, k = 0;
  string ans;
  while(i >= 0 || j >= 0 || k > 0) {
    if(i >= 0 && a[i--] == '1') k += 1;
    if(j >= 0 && b[j--] == '1') k += 1;
    ans.append(to_string(k%2));
    k = k/2;
  }
  reverse(ans.begin(), ans.end());
  return ans;
}

