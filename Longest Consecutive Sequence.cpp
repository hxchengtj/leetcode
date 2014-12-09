// review
class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        unordered_set<int> m;
        unordered_set<int>::iterator iter;
        int ans = 0, i, j, k;
        for(int &n:num)
            m.insert(n);
        for(i = 0; i < num.size(); i++) {
            for(j = 0, k = num[i], iter = m.find(num[i]); iter != m.end(); j++, k--, iter = m.find(k)) 
                m.erase(iter);
            for(k = num[i]+1, iter = m.find(k); iter != m.end(); j++, k++, iter = m.find(k)) 
                m.erase(iter);
            ans = max(ans, j);
        }
        return ans;
    }
};