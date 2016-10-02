class Solution {
public:
    string minAbbreviation(string target, vector<string>& dictionary) {
        int m = target.size(), n = 0;
        //vector<vector<int>> f;
        unordered_map<int, vector<int>> MAP;
        for(auto& s:dictionary) {
            if(s.size() == m) {
                //int k = f.size();
                n++;
                for(int i = 0; i < m; i++) {
                    if(s[i] != target[i]) {
                        //if(k == f.size()) f.push_back({i});
                        //else f[k].push_back(i);
                        //MAP[i].push_back(k);
                        MAP[i].push_back(n);
                    }
                }
            }
        }
        int cnt = 0;
        vector<bool> visited(n);
        //printf("%d\n", n);
        string ret, ans;
        ans = target;
        dfs(target, 0, visited, ret, cnt, MAP, ans);
        return ans;
    }
    void dfs(string& target, int idx, vector<bool>& visited, string ret, int cnt, unordered_map<int, vector<int>>& MAP, string& ans) {
        int m = target.size();
        if(idx == m || visited.size() == cnt) {
            if(m > idx) ret += to_string(m-idx);
            if(visited.size() == cnt && ret.size() < ans.size()) ans = ret;
            return;
        } 
        //printf("ret:%s\n", ret.c_str());
        for(int i = idx; i < m; i++) {
            vector<int> tmp;
            for(int j:MAP[i]) {
                if(!visited[j]) {
                    visited[j] = true;
                    tmp.push_back(j);
                    cnt++;
                }
            }
            int n = ret.size();
            if(i == idx) ret.push_back(target[i]);
            else ret.append(to_string(i-idx) + target[i]);
            //printf("ret:%s\n", ret.c_str());
            dfs(target, i+1, visited, ret, cnt, MAP, ans);
            ret.resize(n);
            for(int j:tmp) {
                visited[j] = false;
                cnt--;
            }
        }
    }
};
