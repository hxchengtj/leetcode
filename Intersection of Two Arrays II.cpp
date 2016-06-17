class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, pair<int, int>> MAP;
        for(int a:nums1) {
            if(MAP.find(a) == MAP.end()) MAP[a] = make_pair(1, 0);
            else MAP[a].first += 1;
        }
        for(int b:nums2) {
            if(MAP.find(b) != MAP.end()) MAP[b].second += 1;
        }
        vector<int> ans;
        for(auto &p:MAP) {
            int n = min(p.second.first, p.second.second);
            for (int i = 0; i < n; i++) ans.push_back(p.first);
        }
        return ans;
    }
};
