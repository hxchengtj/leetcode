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


//version2
class Solution {
public:  
    int hammingWeight(uint32_t n) {
        int ans;
        ans = (n & 0x55555555) + ((n >> 1) & 0x55555555);
        ans = (ans & 0x33333333) + ((ans >> 2) & 0x33333333);
        ans = (ans & 0x0f0f0f0f) + ((ans >> 4) & 0x0f0f0f0f);
        ans = (ans & 0x00ff00ff) + ((ans >> 8) & 0x00ff00ff);
        ans = (ans & 0x0000ffff) + ((ans >> 16) & 0x0000ffff);
        return ans;
    }
}