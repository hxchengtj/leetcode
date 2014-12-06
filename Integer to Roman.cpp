class Solution {
public:
    int a[7] = {1000, 500, 100, 50, 10, 5, 1};
    char c[7] = {'M', 'D', 'C', 'L', 'X', 'V', 'I'};
    string intToRoman(int num) {
        string s;
        int x;
        for(int i = 0; i < 7; i++) {
            x = num/a[i];
            num = num%a[i];
            if(x <= 3)
                s.insert(s.end(), x, c[i]);
            else if(s.size() == 0 || s.back() != c[i-1]){
                s += c[i];
                s += c[i-1];
            }
            else {
                s.pop_back();
                s += c[i];
                s += c[i-2];
            }
        }
        return s;
    }
};
