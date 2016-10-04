/* review again */
class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size(), n = nums2.size();
        vector<int> ans;
        for(int i = max(0, k-n); i <= k && i <= m; i++) {
            vector<int> ret = merge(maxArray(nums1, i), maxArray(nums2, k-i));
            if(greater(ret, 0, ans, 0)) ans = ret;
        }
        return ans;
    }
    vector<int> maxArray(vector<int>& nums, int l) {
        vector<int> ans(l);
        int j = 0, n = nums.size();
        for(int i = 0; i < l; i++) {
            auto iter = max_element(nums.begin()+j, nums.begin()+(n-(l-i)+1));
            j = distance(nums.begin(), iter)+1;
            ans[i] = *iter;
        }
        return ans;
    }
    bool greater(vector<int>& a, int i, vector<int>& b, int j) {
        while(i < a.size() && j < b.size() && a[i] == b[j]) { i++; j++;}
        return j == b.size() || i < a.size() && a[i] > b[j];
    }
    // 此处因为调用的原因不能用&
    vector<int> merge(vector<int> a, vector<int> b) {
        vector<int> ans(a.size()+b.size());
        for(int i = 0, j = 0, k = 0; k < ans.size(); k++) 
            ans[k] = greater(a, i, b, j)?a[i++]:b[j++];
        return ans;
    }
};
