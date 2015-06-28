class Solution {
public:
    int hammingWeight(uint32_t n) {
        int a = 1, b = 0;
        for(int i = 0; i < 32; i++) {
            if( (n & a) != 0)
                b++;
            a = a << 1;
        }
        return b;
    }
};