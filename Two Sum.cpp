class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        unordered_map<int, int> m;
        vector<int> v(2);
        int a;
        for(int i = 0; i < numbers.size(); i++) {
            a = target-numbers[i];
            if (m.find(a) != m.end()) {
                v[0] = m[a];
                v[1] = i+1;
                return v;
            }
            m[numbers[i]] = i+1;
        }
        return v;
    }
};