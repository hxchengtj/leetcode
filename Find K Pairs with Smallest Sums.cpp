class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        if(nums1.size() == 0 || nums2.size() == 0) return {};
        int m = nums1.size(), n = nums2.size(), hsize = min(m, k);
        auto cmp = [&](const pair<int, int>&a, const pair<int, int>&b){
            return nums1[a.first]+nums2[a.second] > nums1[b.first]+nums2[b.second];
        };
        vector<pair<int, int>> h,ans;
        for(int i = 0; i < hsize; i++) h.push_back(make_pair(i, 0));
        make_heap(h.begin(), h.end(), cmp);
        while(k-- > 0 && h.size() > 0) {
            auto t = h[0];
            ans.push_back(make_pair(nums1[t.first], nums2[t.second]));
            pop_heap(h.begin(), h.end(), cmp);
            if(++t.second < n) {
                h.back() = t;
                push_heap(h.begin(), h.end(), cmp);
            } else h.pop_back();
        }
        return ans;
    }
};
