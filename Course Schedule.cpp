class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
         unordered_map<int, vector<int>> m;
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
            if(flag)
                return false;
         }
         return true;
    }
};


//version2
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> graph[numCourses];
        int f[numCourses];
        memset(f, 0, sizeof(f));
        for(auto &t:prerequisites) {
            graph[t.second].push_back(t.first);
            f[t.first]++;
        }
        
        stack<int> stk;
        for(int i = 0; i < numCourses; i++)
            if(f[i] == 0) stk.push(i);
        int n = 0;
        while(!stk.empty()) {
            int i = stk.top();
            stk.pop();
            n++;
            for(auto &a:graph[i]) {
                f[a]--;
                if(f[a] == 0)
                    stk.push(a);
            }
        }
        return n == numCourses;
    }
};