/* review again */
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int diff = 0;
        for(auto& a:nums) diff ^= a;
        // 取出从最低位起第一个1
        diff &= (-diff);
        int num1 = 0, num2 = 0;
        for(auto& a:nums) {
            if(a & diff) num1 ^= a;
            else num2 ^= a;
        }
        return {num1, num2};
    }
};
