//redo
class Solution {
public:
    int superPow(int a, vector<int>& b) {
        if(b.size() == 0) return 1;
        a %= 1337;
        int l = b.back();
        b.pop_back();
        return my_pow(superPow(a, b), 10)*my_pow(a, l) %1337;
    }
    int my_pow(int a, int b) {
        int r = 1;
        for(int i = 0; i < b; i++) r = (r*a)%1337;
        return r;
    }
};
