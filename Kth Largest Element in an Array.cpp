class Solution {
public:
    int findupper(vector<int> &v, int n) {
        int l = 0, r = v.size(), m;
        while(l < r) {
            m = l + (r-l)/2;
            if(v[m] < n)
                l = m+1;
            else
                r = m;
        }
        return l;
    }
    void quicksort(vector<int> & v, int l, int r) {
        if (l >= r)
            return;
        int m = l;
        for(int i = l+1; i < r; i++) {
            if(v[i] < v[l]) {
                swap(v[m], v[i]);
                swap(v[m+1], v[i]);
                m += 1;
            }
        }
        quicksort(v, l, m);
        quicksort(v, m+1, r);
        
    }
    int findKthLargest(vector<int>& nums, int k) {
        vector<int> v(nums.begin(), nums.begin()+k);
        quicksort(v, 0, k);
        for(int i = k; i < nums.size(); i++)
        {
            if(nums[i] > v[0]) {
                v.erase(v.begin());
                int j = findupper(v, nums[i]);
                v.insert(v.begin()+j, nums[i]);
            }
        }
        return v[0];
    }
    
};