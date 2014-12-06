class Solution {
public:
    string simplifyPath(string path) {
        stack<string> s;
        string t = "", ans;
        for(int i = 0; i <= path.size(); i++) {
            if(i < path.size() && path[i] != '/')
                t += path[i];
            else if(t.size()) {
                if(t.size() == 2 && t[0] == '.' && t[1] == '.') {
                    if(!s.empty())
                        s.pop();
                }
                else if(t.size() != 1 || t[0] != '.')
                    s.push(t);
                t = "";
            }
        }
        while(!s.empty()) {
            ans.insert(0, "/" + s.top());
            s.pop();
        }
        if(ans.size() == 0)
            ans = "/";
        return ans;
    }
};
