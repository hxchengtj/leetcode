// 写的太乱。。
// review
class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        unordered_map<string, vector<int>> m;
        vector<int> ans;
        int n = L[0].length(), i, j, k, a = L.size(), b = S.size(), x = 0;
        for(i = 0; i < n; i++) {
            for(string &s:L)
                m[s].clear();
            for(string &s:L)
                m[s].push_back(-1);
            j = i;
            k = i;
            x = a;
            while(k + n <= b) {
                for(; k + n <= b && x; k += n) {
                    string t = S.substr(k, n);
                    if(m.find(t) != m.end()) {
                        vector<int> &v = m[t];
                        int minv = v[0], z = 0, y = 0;
                        for(y = 1; y < v.size(); y++) {
                            if(minv > v[y]) {
                                minv = v[y];
                                z = y;
                            }
                        }
                        if(minv < j) {
                            v[z] = k;
                            x--;
                        }
                        else {
                            j = v[z]+n;
                            v[z] = k;
                            x = a-(k-j)/n-1;
                        }
                    }
                    else {
                        j = k+n;
                        x = a;
                    }
                }
                if(x == 0) {
                    ans.push_back(j);
                    j = j+n;
                    x = 1;
                }
            }
        }
        return ans;
    }
};

vector<int> findsubstring(string s, vector<string>& words) {
  vector<int> ans;
  if(s.size() == 0 || words.size() == 0) return ans;
  unordered_map<string, int> dict;
  for(auto & w:words)
    dict[w]++;
  int m = s.size(), n = words.size(), w = words[0].size();
  for(int i = 0; i < w; i++) {
    int l = i, r = i;
    unordered_map<string, int> mapped;
    while(l+n*w <= m) {
      string t = s.substr(r, w);
      if(dict.find(t) == dict.end()) {
        mapped.clear();
        l = r+w;
        r = l;
      }
      else if(mapped[t] == dict[t]){
        mapped[s.substr(l, w)]--;
        l += w;
      }
      else {
        mapped[t]++;
        r += w;
        if(r-l == n*w) ans.push_back(l);
      }
    }
  }
  return ans;
}

