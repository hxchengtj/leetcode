class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> v;
        if(nums.size() == 0)
            return v;
        int l = nums[0], r = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] == r+1) {
                r = nums[i];
            }
            else {
                string s;
                if(l != r)
                    s = to_string(l) + "->" + to_string(r);
                else
                    s = to_string(l);
                v.push_back(s);
                l = nums[i];
                r = nums[i];
            }
        }
        string s;
        if(l != r)
            s = to_string(l) + "->" + to_string(r);
        else
            s = to_string(l); 
        v.push_back(s);
        return v;
    }
};