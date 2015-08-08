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


//version2
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if(t < 0) return false;
        set<int> s;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            if (i > k) s.erase(nums[i-k-1]);
            auto it = s.insert(nums[i]);
            if(!it.second) return true;

            if(it.first != s.begin()) {
                auto jt = prev(it.first);
                if(*jt < 0) {
                    if(nums[i] <= t + *jt) return true;
                }
                else {
                    if(nums[i]- *jt <= t) return true;
                }
            }

            if(it.first != prev(s.end())) {
                auto jt = next(it.first);
                if(nums[i] < 0) {
                    if(*jt <= t + nums[i]) return true;
                }
                else {
                    if(*jt - nums[i] <= t) return true;
                }
            }
        }
        return false;
    }
};

//redo
bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
  if(t < 0) return false;
  set<int> s;
  int n = nums.size();
  for(int i = 0; i < n; i++) {
    if(i > k) s.erase(nums[i-k-1]);
    auto ip = s.insert(nums[i]);
    if(!ip.second) return true;
    auto it = ip.first;
    if(it != s.begin()) {
      auto ij = prev(it);
      if(*ij > 0 && nums[i]-*ij <= t) return true;
      if(*ij <= 0 && nums[i] <= t+*ij) return true;
    }
    if(it != prev(s.end())) {
      auto ij = next(it);
      if(nums[i] > 0 && *ij-nums[i] <= t) return true;
      if(nums[i] <= 0 && *ij <= t+nums[i]) return true;
    }
  }
  return false;
}

