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

//redo
string simplifyPath(string path) {
  vector<string> v;
  int i = 0, n = path.size();
  while(i < n) {
    int j = i;
    while(j < n && path[j] != '/') j++;
    string s = path.substr(i, j-i);
    if(s == "..") {
      if(!v.empty()) v.pop_back();
    }
    else if(s.size() > 0 && s != ".") v.push_back(s);
    i = j+1;
  }
  if(v.empty()) return "/";
  string ans;
  for(auto &c:v) ans.append('/'+c);
  return ans;
}

