/* review again */
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t a = 1, c = 0;
        for(int i = 0;i < 32; i++) {
            if((a&n) != 0)
                c = (c | (1 << (31-i)));
            a = a << 1;
        }
        return c;
    }
};


//redo
uint32_t reverseBits(uint32_t n) {
  int ans = 0;
  for(int i = 0; i < 32; i++) {
    ans = (ans << 1) | (n & 1);
    n = n >> 1;
  }
}

