class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int a = 0, an = 0, b = 1, bn = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(a == nums[i]) 
                an++;
            else if(b == nums[i])
                bn++;
            else if(an == 0) {
                a = nums[i];
                an = 1;
            }
            else if(bn == 0) {
                b = nums[i];
                bn = 1;
            }
            else {
                an--;
                bn--;
            }
        }
        vector<int> v;
        int aa = 0, bb = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == a)
                aa++;
            else if(nums[i] == b)
                bb++;
        }
        if(aa > nums.size()/3)
            v.push_back(a);
        if(bb > nums.size()/3)
            v.push_back(b);
        return v;
    }

};