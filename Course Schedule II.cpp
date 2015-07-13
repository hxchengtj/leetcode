class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
         unordered_map<int, vector<int>> m;
         vector<int> ret;
         int f[numCourses];
         int n = 0;
         for(int i = 0; i < numCourses; i++)
            f[i] = 0;
         for(int i = 0; i < prerequisites.size(); i++) {
             int course = prerequisites[i].first;
             int pre = prerequisites[i].second;
             if(m.find(pre) == m.end()) {
                vector<int> v;
                v.push_back(course);
                m.insert(make_pair(pre, v));
             }
             else
                m[pre].push_back(course);
            f[course]++;
            if(f[course] == 1)
                n++;
         }
         while(n) {
            bool flag = true;
            for(int i = 0; i < numCourses; i++) 
                if(f[i] == 0) {
                    ret.push_back(i);
                    flag = false;
                    if(m.find(i) != m.end()) {
                        for(auto a:m[i]) {
                            f[a]--;
                            if(f[a] == 0)
                                n--;
                        }
                    }
                    f[i]--;
                }
            if(flag) {
                ret.clear();
                return ret;
            }
         }
         for(int i = 0; i < numCourses; i++) 
            if(f[i] == 0)
                ret.push_back(i);
         return ret;        
    }
};



//version2
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> graph[numCourses];
        int f[numCourses];
        memset(f, 0, sizeof(f));
        for(auto &t:prerequisites) {
            graph[t.second].push_back(t.first);
            f[t.first]++;
        }
        
        vector<int> ans;
        queue<int> q;
        for(int i = 0; i < numCourses; i++)
            if(f[i] == 0) q.push(i);
        
        int n = 0;
        while(!q.empty()) {
            int a = q.front();
            q.pop();
            ans.push_back(a);
            n++;
            for(auto &t:graph[a]) {
                f[t]--;
                if(f[t] == 0) q.push(t);
            }
        }
        if(n != numCourses) ans.clear();
        return ans;
    }
};