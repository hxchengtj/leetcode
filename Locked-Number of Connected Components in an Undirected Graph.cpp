class Solution {
public:
  int countComponents(int n, vector<pair<int, int>>& edges) {
    father.clear();
    father.resize(n);
    for(int i = 0; i < n; i++) father[i] = i;
    int cnt = n;
    for(auto &e:edges) {
      int fa = find_father(e.first), fb = find_father(e.second);
      if(fa != fb) {
        cnt--;
        father[fa] = fb;
      }
    }
    return cnt;
  }
  int find_father(int a) {
    while(a != father[a]) father[a] = find_father(father[a]);
    return father[a];
  }
private:
  vector<int> father;
};
