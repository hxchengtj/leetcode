class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> SET;
        for(int a:nums1) SET.insert(a);
        vector<int> ans;
        for(int b:nums2) {
            if(SET.find(b) != SET.end()) {
                ans.push_back(b);
                SET.erase(b);
            }
        }
        return ans;
    }
};
