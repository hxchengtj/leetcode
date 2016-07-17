class Solution {
public:
    bool isAdditiveNumber(string num) {
        int n = num.size();
        for(int i = 1; i < n; i++)
            for(int j = 1; j < n-i; j++) {
                if (isSum(num.substr(0, i), num.substr(i, j), num.substr(i+j))) return true;
            }
        return false;
    }
    bool isSum(string num1, string num2, string rest) {
        if (num1.size() > 1 && num1[0] == '0' || num2.size() > 1 && num2[0] == '0') return false;
        if(rest.size() < num1.size() || rest.size() < num2.size()) return false;
        string sum = addS(num1, num2);
        if(sum == rest) return true;
        if(sum.size() < rest.size() && sum == rest.substr(0, sum.size())) return isSum(num2, sum, rest.substr(sum.size()));
        else return false;
    }
    string addS(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int c = 0, i = 0;
        string ans;
        while(i < a.size() || i < b.size() || c) {
            if (i < a.size()) c += a[i]-'0';
            if (i < b.size()) c += b[i]-'0';
            ans.push_back(char(c%10+'0'));
            c /= 10;
            i++;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
