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
