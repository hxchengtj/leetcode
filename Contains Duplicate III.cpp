class Solution {
public:
    int findnum(vector<int> & v, int a) {
        int l = 0, r = v.size(), m;
        while(l < r) {
            m = l + (r-l)/2;
            if(v[m] < a)
                l = m+1;
            else
                r = m;
        }
        return l;
    }
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        vector<int> v;
        int b = 0, j = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(i-b>k) {
                j = findnum(v, nums[b]);
                v.erase(v.begin()+j);
                b++;
            }
            j = findnum(v, nums[i]);
            if(j < v.size() && v[j]-nums[i]>=0 && v[j]-nums[i] <= t)
                return true;
            if(j-1 >= 0 && nums[i]-v[j-1] >=0 && nums[i]-v[j-1] <= t)
                return true;
            v.insert(v.begin()+j, nums[i]);
                
        }
        return false;
    }
};