class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        if(n == 1) return {0};
        queue<int> q;
        vector<unordered_set<int>> v(n);
        vector<int> ans;
        for(auto p:edges) {
            v[p.first].insert(p.second);
            v[p.second].insert(p.first);
        }
        for(int i = 0; i < n; i++) 
            if(v[i].size() == 1) q.push(i);
        q.push(-1);
        while(!q.empty()) {
            auto t = q.front();
            q.pop();
            if (t == -1) {
                if(!q.empty()) {
                    q.push(-1);
                    ans.clear();
                }
            } else {
                ans.push_back(t);
                for(auto j:v[t]) {
                    v[j].erase(t);
                    if(v[j].size() == 1) q.push(j);
                }
            }
        }
        return ans;
    }
};
