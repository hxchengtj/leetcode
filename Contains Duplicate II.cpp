class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        int b = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(i-b > k) {
                m.erase(nums[b]);
                b++;
            }
            if(m.find(nums[i]) != m.end())
                return true;
            else
                m.insert(pair<int, int>(nums[i], 1));
        }
        return false;
    }
};