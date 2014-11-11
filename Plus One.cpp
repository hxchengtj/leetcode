class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int a = 1;
        for(int i = digits.size()-1; i >= 0; i--) {
            digits[i] += a;
            a = digits[i] / 10;
            digits[i] %= 10;
        }
        if(a)
            digits.insert(digits.begin(), a);
        return digits;
    }
};