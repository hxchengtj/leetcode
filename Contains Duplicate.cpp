class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> m;
        for(int i = 0; i < nums.size(); i++) {
            if(m.find(nums[i]) != m.end())
                return true;
            m.insert(pair<int, int>(nums[i], 1));
        }
        return false;
    }
};


//redo
bool containsDuplicate(vector<int>& nums) {
  unordered_set<int> s;
  for(auto a:nums){
    if(s.find(a) != s.end()) return true;
    s.insert(a);
  }
  return false;
}
