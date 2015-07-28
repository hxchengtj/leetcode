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

//redo
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> s;
        int b = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(i-b>k) s.erase(nums[b++]);
            if(s.find(nums[i]) != s.end()) return true;
            else s.insert(nums[i]);
        }
        return false;
    }
};


//redo2
bool containDuplicate(vector<int>& nums, int k) {
  if(k <= 0) return false;
  unordered_set<int> s;
  for(int i = 0; i < nums.size(); i++) {
    if(i > k) s.erase(nums[i-k-1]);
    if(s.find(nums[i]) != s.end()) return true;
    s.insert(nums[i]);
  }
  return false;
}

