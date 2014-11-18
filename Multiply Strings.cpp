class Solution {
public:
    string multiply(string num1, string num2) {
        int f[num1.size()+num2.size()];
        int i, j, k, a = 0, b, c;
        for(i = 0; i < num1.size()+num2.size(); i++) 
            f[i] = 0;
        for(i = num1.size()-1; i >= 0; i--) {
            a = 0;
            for(j = num2.size()-1; j >= 0; j--) {
                b = num1[i]-'0';
                c = num2[j]-'0';
                a = b*c + a + f[i+j+1];
                f[i+j+1] = a%10;
                a = a/10;
            }
            k = i+j+1;
           // while(a > 0 && k >=0) {
                a = f[k]+a;
                f[k] = a%10;
                a = a/10;
                k--;
           // }
        }
        bool x = true;
        string s;
        for(i = 0; i < num1.size()+num2.size(); i++) {
            if(x && !f[i])
                continue;
            x = false;
            s += (f[i] + '0');
        }
        if(!s.size())
            s += '0';
        return s;
    }
};