class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for(int a:nums) m[a]++;
        vector<pair<int, int>> v;
        for(auto &p:m) v.push_back(make_pair(-p.second, p.first));
        make_heap(v.begin(), v.begin()+k);
        for(int i=k; i < v.size(); i++) {
            if(v[i] < v[0]) {
                pop_heap(v.begin(), v.begin()+k);
                v[k-1] = v[i];
                push_heap(v.begin(), v.begin()+k);
            }
        }
        vector<int> ans;
        for(int i = 0; i < k; i++) ans.push_back(v[i].second);
        return ans;
    }
};