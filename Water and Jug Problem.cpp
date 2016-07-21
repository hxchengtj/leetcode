//redo
class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if(x+y == z) return true;
        return x+y < z ? false:(z%gcd(max(x,y), min(x,y)) == 0);
    }
    int gcd(int x, int y) {
        return y? gcd(y, x%y):x;
    }
};
