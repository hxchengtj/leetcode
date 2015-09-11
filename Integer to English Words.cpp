class Solution {
public:
    vector<string> v; 
    string a[20] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    string b[10] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    void __numberToWords(int x) {
        int y = x%100;
        if(y > 0) {
            if(y < 20) v.push_back(a[y]);
            else {
                if(y%10 > 0) v.push_back(a[y%10]);
                if(y/10 > 0) v.push_back(b[y/10]);
            }
        }
        int z = x/100;
        if(z > 0) {
            v.push_back("Hundred");
            v.push_back(a[z]);
        }
    }
    string numberToWords(int num) {
        if(num < 0) return "";
        if(num == 0) return "Zero";
        int i = 0;
        v.clear();
        
        string c[3] = {"Thousand", "Million", "Billion"};
        while(num > 0) {
            int x = num%1000;
            if(x > 0) {
                if(i > 0) v.push_back(c[i-1]);
                __numberToWords(x);
            }
            num /= 1000;
            i++;
        }
        string s(v.back());
        for(int i = v.size()-2; i >= 0; i--)
            s.append(" " + v[i]);
        return s;
    }
};