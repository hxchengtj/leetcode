class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int a, n = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(n == 0) {
                a = nums[i];
                n++;
            }
            else if(a == nums[i])
                n++;
            else
                n--;
        }
        return a;
    }
};