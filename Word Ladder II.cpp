/* review again */
class Solution {
public:
    vector<vector<string> > ans;
    unordered_set<string> m;
    vector<string> q;
    vector<int> g;
    vector<string> now;
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        int n, i, j, k, l = 0, x, y = INT_MIN;
        string s;
        char c, t;
        n = (*dict.begin()).size();
        m.insert(start);
        q.push_back(start);
        g.push_back(-1);
        g.push_back(0);
        x = 0;
        while(l < q.size()) {
            if(l > g.back())
                g.push_back(q.size()-1);
            s = q[l];
            if(s == end) {
                x = g.size()-1;
                break;
            }
            if(mycompare(s, end)) {
                x = g.size();
                break;
            }
            for(i = 0; i < n; i++)
                for(j = 0; j < 26; j++) {
                    c = 'a' + j;
                    if(c != s[i]) {
                        t = s[i];
                        s[i] = c;
                        if(dict.find(s) != dict.end() && m.find(s) == m.end()) {
                            m.insert(s);
                            q.push_back(s);
                        }
                        s[i] = t;
                    }
                }
            l++;
        }
        now.resize(x);
        if(x) {
            now[x-1] = end;
            dfs(x-1, end);
        }
        return ans;
    }
    void dfs(int a, string &t) {
        if(a <= 0) {
            ans.push_back(now);
            return;
        }
        for(int i = g[a-1]+1; i <= g[a]; i++) {
            if(mycompare(t, q[i])) {
                now[a-1] = q[i];
                dfs(a-1, q[i]);
            }
        }
    }
    bool mycompare(string &x, string &y) {
        bool b = false;
        for(int i = 0; i < x.length(); i++) {
            if(x[i] != y[i]) {
                if(b)
                    return false;
                b = true;
            }
        }
        return b;
    }
};

//redo
vector<vector<string>> ans;
vector<string> v;
vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
  unordered_map<string, int> m;
  queue<string> q;
  q.push(start);
  m[start] = 1;
  int curcount = 0;
  while(!q.empty()) {
    string t = q.front();
    q.pop();
    curcount = m[t];
    if(t == end) break;
    for(int i = 0; i < t.size(); i++) {
      char c = t[i];
      for(t[i] = 'a'; t[i] <= 'z'; t[i]++) {
        if((t == end || dict.find(t) != dict.end()) && m.find(t) == m.end()) {
          m[t] = curcount+1;
          q.push(t);
        }
      }
      t[i] = c;
    }
  }
  if(m.find(end) == m.end()) return {};
  ans.clear(); v.clear();
  __findLadders(end, m[end], m);
  return ans;
}

void __findLadders(string end, int curcount, unordered_map<string, int>& m) {
  if(curcount == 1) {
    v.push_back(end);
    reverse(v.begin(), v.end());
    ans.push_back(v);
    reverse(v.begin(), v.end());
    v.pop_back();
    return;
  }
  v.push_back(end);
  for(int i = 0; i < end.size(); i++) {
    char c = end[i];
    for(end[i] = 'a'; end[i] <= 'z'; end[i]++)
      if(m.find(end) != m.end() && m[end] == curcount-1)
        __findLadders(end, curcount-1, m);
    end[i] = c;
  }
  v.pop_back();
}

