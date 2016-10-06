class Solution {
public:
    int countOne(int num) {
        num = (num&0x55555555)+((num>>1)&0x55555555);
        num = (num&0x33333333)+((num>>2)&0x33333333);
        num = (num&0x0f0f0f0f)+((num>>4)&0x0f0f0f0f);
        num = (num&0x00ff00ff)+((num>>8)&0x00ff00ff);
        num = (num&0x0000ffff)+((num>>16)&0x0000ffff);
        return num;
        
    }
    bool isPowerOfFour(int num) {
        return (num&0x55555555) != 0 && countOne(num) == 1;
    }
};

//version2
class Solution {
public:
    bool isPowerOfFour(int num) {
        return num > 0 && (num & (num-1)) == 0 && (num&0x55555555) != 0;
    }
};
