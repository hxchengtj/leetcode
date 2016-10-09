class Solution {
public:
    string addStrings(string num1, string num2) {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        int i = 0, j = 0, n1 = num1.size(), n2 = num2.size();
        int c = 0;
        string s;
        while(i < n1 || j < n2 || c) {
            if(i < n1) c += num1[i++]-'0';
            if(j < n2) c += num2[j++]-'0';
            s.push_back((c%10)+'0');
            c /= 10;
        }
        reverse(s.begin(), s.end());
        return s;
    }
};
